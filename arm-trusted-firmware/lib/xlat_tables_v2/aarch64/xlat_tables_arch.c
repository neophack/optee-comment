/*
 * Copyright (c) 2017-2018, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <arch.h>
#include <arch_helpers.h>
#include <assert.h>
#include <cassert.h>
#include <sys/types.h>
#include <utils_def.h>
#include <xlat_tables_v2.h>
#include "../xlat_tables_private.h"

uint32_t mmu_cfg_params[MMU_CFG_PARAM_MAX];

/*
 * Returns 1 if the provided granule size is supported, 0 otherwise.
 */
int xlat_arch_is_granule_size_supported(size_t size)
{
	u_register_t id_aa64mmfr0_el1 = read_id_aa64mmfr0_el1();

	if (size == (4U * 1024U)) {
		return ((id_aa64mmfr0_el1 >> ID_AA64MMFR0_EL1_TGRAN4_SHIFT) &
			 ID_AA64MMFR0_EL1_TGRAN4_MASK) ==
			 ID_AA64MMFR0_EL1_TGRAN4_SUPPORTED;
	} else if (size == (16U * 1024U)) {
		return ((id_aa64mmfr0_el1 >> ID_AA64MMFR0_EL1_TGRAN16_SHIFT) &
			 ID_AA64MMFR0_EL1_TGRAN16_MASK) ==
			 ID_AA64MMFR0_EL1_TGRAN16_SUPPORTED;
	} else if (size == (64U * 1024U)) {
		return ((id_aa64mmfr0_el1 >> ID_AA64MMFR0_EL1_TGRAN64_SHIFT) &
			 ID_AA64MMFR0_EL1_TGRAN64_MASK) ==
			 ID_AA64MMFR0_EL1_TGRAN64_SUPPORTED;
	}

	return 0;
}

size_t xlat_arch_get_max_supported_granule_size(void)
{
	if (xlat_arch_is_granule_size_supported(64U * 1024U)) {
		return 64U * 1024U;
	} else if (xlat_arch_is_granule_size_supported(16U * 1024U)) {
		return 16U * 1024U;
	} else {
		assert(xlat_arch_is_granule_size_supported(4U * 1024U));
		return 4U * 1024U;
	}
}

unsigned long long tcr_physical_addr_size_bits(unsigned long long max_addr)
{
	/* Physical address can't exceed 48 bits */
	assert((max_addr & ADDR_MASK_48_TO_63) == 0);

	/* 48 bits address */
	if (max_addr & ADDR_MASK_44_TO_47)
		return TCR_PS_BITS_256TB;

	/* 44 bits address */
	if (max_addr & ADDR_MASK_42_TO_43)
		return TCR_PS_BITS_16TB;

	/* 42 bits address */
	if (max_addr & ADDR_MASK_40_TO_41)
		return TCR_PS_BITS_4TB;

	/* 40 bits address */
	if (max_addr & ADDR_MASK_36_TO_39)
		return TCR_PS_BITS_1TB;

	/* 36 bits address */
	if (max_addr & ADDR_MASK_32_TO_35)
		return TCR_PS_BITS_64GB;

	return TCR_PS_BITS_4GB;
}

#if ENABLE_ASSERTIONS
/*
 * Physical Address ranges supported in the AArch64 Memory Model. Value 0b110 is
 * supported in ARMv8.2 onwards.
 */
static const unsigned int pa_range_bits_arr[] = {
	PARANGE_0000, PARANGE_0001, PARANGE_0010, PARANGE_0011, PARANGE_0100,
	PARANGE_0101, PARANGE_0110
};

unsigned long long xlat_arch_get_max_supported_pa(void)
{
	u_register_t pa_range = read_id_aa64mmfr0_el1() &
						ID_AA64MMFR0_EL1_PARANGE_MASK;

	/* All other values are reserved */
	assert(pa_range < ARRAY_SIZE(pa_range_bits_arr));

	return (1ULL << pa_range_bits_arr[pa_range]) - 1ULL;
}
#endif /* ENABLE_ASSERTIONS*/

int is_mmu_enabled_ctx(const xlat_ctx_t *ctx)
{
	if (ctx->xlat_regime == EL1_EL0_REGIME) {
		assert(xlat_arch_current_el() >= 1);
		return (read_sctlr_el1() & SCTLR_M_BIT) != 0;
	} else {
		assert(ctx->xlat_regime == EL3_REGIME);
		assert(xlat_arch_current_el() >= 3);
		return (read_sctlr_el3() & SCTLR_M_BIT) != 0;
	}
}


void xlat_arch_tlbi_va(uintptr_t va)
{
#if IMAGE_EL == 1
	assert(IS_IN_EL(1));
	xlat_arch_tlbi_va_regime(va, EL1_EL0_REGIME);
#elif IMAGE_EL == 3
	assert(IS_IN_EL(3));
	xlat_arch_tlbi_va_regime(va, EL3_REGIME);
#endif
}

void xlat_arch_tlbi_va_regime(uintptr_t va, int xlat_regime)
{
	/*
	 * Ensure the translation table write has drained into memory before
	 * invalidating the TLB entry.
	 */
	dsbishst();

	/*
	 * This function only supports invalidation of TLB entries for the EL3
	 * and EL1&0 translation regimes.
	 *
	 * Also, it is architecturally UNDEFINED to invalidate TLBs of a higher
	 * exception level (see section D4.9.2 of the ARM ARM rev B.a).
	 */
	if (xlat_regime == EL1_EL0_REGIME) {
		assert(xlat_arch_current_el() >= 1);
		tlbivaae1is(TLBI_ADDR(va));
	} else {
		assert(xlat_regime == EL3_REGIME);
		assert(xlat_arch_current_el() >= 3);
		tlbivae3is(TLBI_ADDR(va));
	}
}

void xlat_arch_tlbi_va_sync(void)
{
	/*
	 * A TLB maintenance instruction can complete at any time after
	 * it is issued, but is only guaranteed to be complete after the
	 * execution of DSB by the PE that executed the TLB maintenance
	 * instruction. After the TLB invalidate instruction is
	 * complete, no new memory accesses using the invalidated TLB
	 * entries will be observed by any observer of the system
	 * domain. See section D4.8.2 of the ARMv8 (issue k), paragraph
	 * "Ordering and completion of TLB maintenance instructions".
	 */
	dsbish();

	/*
	 * The effects of a completed TLB maintenance instruction are
	 * only guaranteed to be visible on the PE that executed the
	 * instruction after the execution of an ISB instruction by the
	 * PE that executed the TLB maintenance instruction.
	 */
	isb();
}

int xlat_arch_current_el(void)
{
	int el = GET_EL(read_CurrentEl());

	assert(el > 0);

	return el;
}

void setup_mmu_cfg(unsigned int flags,
		const uint64_t *base_table,
		unsigned long long max_pa,
		uintptr_t max_va)
{
	uint64_t mair, ttbr, tcr;
	uintptr_t virtual_addr_space_size;

	/* Set attributes in the right indices of the MAIR. */
	mair = MAIR_ATTR_SET(ATTR_DEVICE, ATTR_DEVICE_INDEX);
	mair |= MAIR_ATTR_SET(ATTR_IWBWA_OWBWA_NTR, ATTR_IWBWA_OWBWA_NTR_INDEX);
	mair |= MAIR_ATTR_SET(ATTR_NON_CACHEABLE, ATTR_NON_CACHEABLE_INDEX);

	ttbr = (uint64_t) base_table;

	/*
	 * Limit the input address ranges and memory region sizes translated
	 * using TTBR0 to the given virtual address space size.
	 */
	assert(max_va < ((uint64_t) UINTPTR_MAX));

	virtual_addr_space_size = max_va + 1;
	assert(CHECK_VIRT_ADDR_SPACE_SIZE(virtual_addr_space_size));

	/*
	 * __builtin_ctzll(0) is undefined but here we are guaranteed that
	 * virtual_addr_space_size is in the range [1,UINTPTR_MAX].
	 */
	tcr = (uint64_t) 64 - __builtin_ctzll(virtual_addr_space_size);

	/*
	 * Set the cacheability and shareability attributes for memory
	 * associated with translation table walks.
	 */
	if ((flags & XLAT_TABLE_NC) != 0) {
		/* Inner & outer non-cacheable non-shareable. */
		tcr |= TCR_SH_NON_SHAREABLE |
			TCR_RGN_OUTER_NC | TCR_RGN_INNER_NC;
	} else {
		/* Inner & outer WBWA & shareable. */
		tcr |= TCR_SH_INNER_SHAREABLE |
			TCR_RGN_OUTER_WBA | TCR_RGN_INNER_WBA;
	}

	/*
	 * It is safer to restrict the max physical address accessible by the
	 * hardware as much as possible.
	 */
	unsigned long long tcr_ps_bits = tcr_physical_addr_size_bits(max_pa);

#if IMAGE_EL == 1
	assert(IS_IN_EL(1));
	/*
	 * TCR_EL1.EPD1: Disable translation table walk for addresses that are
	 * translated using TTBR1_EL1.
	 */
	tcr |= TCR_EPD1_BIT | (tcr_ps_bits << TCR_EL1_IPS_SHIFT);
#elif IMAGE_EL == 3
	assert(IS_IN_EL(3));
	tcr |= TCR_EL3_RES1 | (tcr_ps_bits << TCR_EL3_PS_SHIFT);
#endif

	mmu_cfg_params[MMU_CFG_MAIR0] = (uint32_t) mair;
	mmu_cfg_params[MMU_CFG_TCR] = (uint32_t) tcr;

	/* Set TTBR bits as well */
	if (ARM_ARCH_AT_LEAST(8, 2)) {
		/*
		 * Enable CnP bit so as to share page tables with all PEs. This
		 * is mandatory for ARMv8.2 implementations.
		 */
		ttbr |= TTBR_CNP_BIT;
	}

	mmu_cfg_params[MMU_CFG_TTBR0_LO] = (uint32_t) ttbr;
	mmu_cfg_params[MMU_CFG_TTBR0_HI] = (uint32_t) (ttbr >> 32);
}
