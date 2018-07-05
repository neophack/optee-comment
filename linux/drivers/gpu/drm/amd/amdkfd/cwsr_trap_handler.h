/*
 * Copyright 2018 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

static const uint32_t cwsr_trap_gfx8_hex[] = {
	0xbf820001, 0xbf820125,
	0xb8f4f802, 0x89748674,
	0xb8f5f803, 0x8675ff75,
	0x00000400, 0xbf850011,
	0xc00a1e37, 0x00000000,
	0xbf8c007f, 0x87777978,
	0xbf840002, 0xb974f802,
	0xbe801d78, 0xb8f5f803,
	0x8675ff75, 0x000001ff,
	0xbf850002, 0x80708470,
	0x82718071, 0x8671ff71,
	0x0000ffff, 0xb974f802,
	0xbe801f70, 0xb8f5f803,
	0x8675ff75, 0x00000100,
	0xbf840006, 0xbefa0080,
	0xb97a0203, 0x8671ff71,
	0x0000ffff, 0x80f08870,
	0x82f18071, 0xbefa0080,
	0xb97a0283, 0xbef60068,
	0xbef70069, 0xb8fa1c07,
	0x8e7a9c7a, 0x87717a71,
	0xb8fa03c7, 0x8e7a9b7a,
	0x87717a71, 0xb8faf807,
	0x867aff7a, 0x00007fff,
	0xb97af807, 0xbef2007e,
	0xbef3007f, 0xbefe0180,
	0xbf900004, 0x877a8474,
	0xb97af802, 0xbf8e0002,
	0xbf88fffe, 0xbef8007e,
	0x8679ff7f, 0x0000ffff,
	0x8779ff79, 0x00040000,
	0xbefa0080, 0xbefb00ff,
	0x00807fac, 0x867aff7f,
	0x08000000, 0x8f7a837a,
	0x877b7a7b, 0x867aff7f,
	0x70000000, 0x8f7a817a,
	0x877b7a7b, 0xbeef007c,
	0xbeee0080, 0xb8ee2a05,
	0x806e816e, 0x8e6e8a6e,
	0xb8fa1605, 0x807a817a,
	0x8e7a867a, 0x806e7a6e,
	0xbefa0084, 0xbefa00ff,
	0x01000000, 0xbefe007c,
	0xbefc006e, 0xc0611bfc,
	0x0000007c, 0x806e846e,
	0xbefc007e, 0xbefe007c,
	0xbefc006e, 0xc0611c3c,
	0x0000007c, 0x806e846e,
	0xbefc007e, 0xbefe007c,
	0xbefc006e, 0xc0611c7c,
	0x0000007c, 0x806e846e,
	0xbefc007e, 0xbefe007c,
	0xbefc006e, 0xc0611cbc,
	0x0000007c, 0x806e846e,
	0xbefc007e, 0xbefe007c,
	0xbefc006e, 0xc0611cfc,
	0x0000007c, 0x806e846e,
	0xbefc007e, 0xbefe007c,
	0xbefc006e, 0xc0611d3c,
	0x0000007c, 0x806e846e,
	0xbefc007e, 0xb8f5f803,
	0xbefe007c, 0xbefc006e,
	0xc0611d7c, 0x0000007c,
	0x806e846e, 0xbefc007e,
	0xbefe007c, 0xbefc006e,
	0xc0611dbc, 0x0000007c,
	0x806e846e, 0xbefc007e,
	0xbefe007c, 0xbefc006e,
	0xc0611dfc, 0x0000007c,
	0x806e846e, 0xbefc007e,
	0xb8eff801, 0xbefe007c,
	0xbefc006e, 0xc0611bfc,
	0x0000007c, 0x806e846e,
	0xbefc007e, 0xbefe007c,
	0xbefc006e, 0xc0611b3c,
	0x0000007c, 0x806e846e,
	0xbefc007e, 0xbefe007c,
	0xbefc006e, 0xc0611b7c,
	0x0000007c, 0x806e846e,
	0xbefc007e, 0x867aff7f,
	0x04000000, 0xbef30080,
	0x8773737a, 0xb8ee2a05,
	0x806e816e, 0x8e6e8a6e,
	0xb8f51605, 0x80758175,
	0x8e758475, 0x8e7a8275,
	0xbefa00ff, 0x01000000,
	0xbef60178, 0x80786e78,
	0x82798079, 0xbefc0080,
	0xbe802b00, 0xbe822b02,
	0xbe842b04, 0xbe862b06,
	0xbe882b08, 0xbe8a2b0a,
	0xbe8c2b0c, 0xbe8e2b0e,
	0xc06b003c, 0x00000000,
	0xc06b013c, 0x00000010,
	0xc06b023c, 0x00000020,
	0xc06b033c, 0x00000030,
	0x8078c078, 0x82798079,
	0x807c907c, 0xbf0a757c,
	0xbf85ffeb, 0xbef80176,
	0xbeee0080, 0xbefe00c1,
	0xbeff00c1, 0xbefa00ff,
	0x01000000, 0xe0724000,
	0x6e1e0000, 0xe0724100,
	0x6e1e0100, 0xe0724200,
	0x6e1e0200, 0xe0724300,
	0x6e1e0300, 0xbefe00c1,
	0xbeff00c1, 0xb8f54306,
	0x8675c175, 0xbf84002c,
	0xbf8a0000, 0x867aff73,
	0x04000000, 0xbf840028,
	0x8e758675, 0x8e758275,
	0xbefa0075, 0xb8ee2a05,
	0x806e816e, 0x8e6e8a6e,
	0xb8fa1605, 0x807a817a,
	0x8e7a867a, 0x806e7a6e,
	0x806eff6e, 0x00000080,
	0xbefa00ff, 0x01000000,
	0xbefc0080, 0xd28c0002,
	0x000100c1, 0xd28d0003,
	0x000204c1, 0xd1060002,
	0x00011103, 0x7e0602ff,
	0x00000200, 0xbefc00ff,
	0x00010000, 0xbe80007b,
	0x867bff7b, 0xff7fffff,
	0x877bff7b, 0x00058000,
	0xd8ec0000, 0x00000002,
	0xbf8c007f, 0xe0765000,
	0x6e1e0002, 0x32040702,
	0xd0c9006a, 0x0000eb02,
	0xbf87fff7, 0xbefb0000,
	0xbeee00ff, 0x00000400,
	0xbefe00c1, 0xbeff00c1,
	0xb8f52a05, 0x80758175,
	0x8e758275, 0x8e7a8875,
	0xbefa00ff, 0x01000000,
	0xbefc0084, 0xbf0a757c,
	0xbf840015, 0xbf11017c,
	0x8075ff75, 0x00001000,
	0x7e000300, 0x7e020301,
	0x7e040302, 0x7e060303,
	0xe0724000, 0x6e1e0000,
	0xe0724100, 0x6e1e0100,
	0xe0724200, 0x6e1e0200,
	0xe0724300, 0x6e1e0300,
	0x807c847c, 0x806eff6e,
	0x00000400, 0xbf0a757c,
	0xbf85ffef, 0xbf9c0000,
	0xbf8200ca, 0xbef8007e,
	0x8679ff7f, 0x0000ffff,
	0x8779ff79, 0x00040000,
	0xbefa0080, 0xbefb00ff,
	0x00807fac, 0x8676ff7f,
	0x08000000, 0x8f768376,
	0x877b767b, 0x8676ff7f,
	0x70000000, 0x8f768176,
	0x877b767b, 0x8676ff7f,
	0x04000000, 0xbf84001e,
	0xbefe00c1, 0xbeff00c1,
	0xb8f34306, 0x8673c173,
	0xbf840019, 0x8e738673,
	0x8e738273, 0xbefa0073,
	0xb8f22a05, 0x80728172,
	0x8e728a72, 0xb8f61605,
	0x80768176, 0x8e768676,
	0x80727672, 0x8072ff72,
	0x00000080, 0xbefa00ff,
	0x01000000, 0xbefc0080,
	0xe0510000, 0x721e0000,
	0xe0510100, 0x721e0000,
	0x807cff7c, 0x00000200,
	0x8072ff72, 0x00000200,
	0xbf0a737c, 0xbf85fff6,
	0xbef20080, 0xbefe00c1,
	0xbeff00c1, 0xb8f32a05,
	0x80738173, 0x8e738273,
	0x8e7a8873, 0xbefa00ff,
	0x01000000, 0xbef60072,
	0x8072ff72, 0x00000400,
	0xbefc0084, 0xbf11087c,
	0x8073ff73, 0x00008000,
	0xe0524000, 0x721e0000,
	0xe0524100, 0x721e0100,
	0xe0524200, 0x721e0200,
	0xe0524300, 0x721e0300,
	0xbf8c0f70, 0x7e000300,
	0x7e020301, 0x7e040302,
	0x7e060303, 0x807c847c,
	0x8072ff72, 0x00000400,
	0xbf0a737c, 0xbf85ffee,
	0xbf9c0000, 0xe0524000,
	0x761e0000, 0xe0524100,
	0x761e0100, 0xe0524200,
	0x761e0200, 0xe0524300,
	0x761e0300, 0xb8f22a05,
	0x80728172, 0x8e728a72,
	0xb8f61605, 0x80768176,
	0x8e768676, 0x80727672,
	0x80f2c072, 0xb8f31605,
	0x80738173, 0x8e738473,
	0x8e7a8273, 0xbefa00ff,
	0x01000000, 0xbefc0073,
	0xc031003c, 0x00000072,
	0x80f2c072, 0xbf8c007f,
	0x80fc907c, 0xbe802d00,
	0xbe822d02, 0xbe842d04,
	0xbe862d06, 0xbe882d08,
	0xbe8a2d0a, 0xbe8c2d0c,
	0xbe8e2d0e, 0xbf06807c,
	0xbf84fff1, 0xb8f22a05,
	0x80728172, 0x8e728a72,
	0xb8f61605, 0x80768176,
	0x8e768676, 0x80727672,
	0xbefa0084, 0xbefa00ff,
	0x01000000, 0xc0211cfc,
	0x00000072, 0x80728472,
	0xc0211c3c, 0x00000072,
	0x80728472, 0xc0211c7c,
	0x00000072, 0x80728472,
	0xc0211bbc, 0x00000072,
	0x80728472, 0xc0211bfc,
	0x00000072, 0x80728472,
	0xc0211d3c, 0x00000072,
	0x80728472, 0xc0211d7c,
	0x00000072, 0x80728472,
	0xc0211a3c, 0x00000072,
	0x80728472, 0xc0211a7c,
	0x00000072, 0x80728472,
	0xc0211dfc, 0x00000072,
	0x80728472, 0xc0211b3c,
	0x00000072, 0x80728472,
	0xc0211b7c, 0x00000072,
	0x80728472, 0xbf8c007f,
	0xbefc0073, 0xbefe006e,
	0xbeff006f, 0x867375ff,
	0x000003ff, 0xb9734803,
	0x867375ff, 0xfffff800,
	0x8f738b73, 0xb973a2c3,
	0xb977f801, 0x8673ff71,
	0xf0000000, 0x8f739c73,
	0x8e739073, 0xbef60080,
	0x87767376, 0x8673ff71,
	0x08000000, 0x8f739b73,
	0x8e738f73, 0x87767376,
	0x8673ff74, 0x00800000,
	0x8f739773, 0xb976f807,
	0x8671ff71, 0x0000ffff,
	0x86fe7e7e, 0x86ea6a6a,
	0xb974f802, 0xbf8a0000,
	0x95807370, 0xbf810000,
};


static const uint32_t cwsr_trap_gfx9_hex[] = {
	0xbf820001, 0xbf82015a,
	0xb8f8f802, 0x89788678,
	0xb8f1f803, 0x866eff71,
	0x00000400, 0xbf850034,
	0x866eff71, 0x00000800,
	0xbf850003, 0x866eff71,
	0x00000100, 0xbf840008,
	0x866eff78, 0x00002000,
	0xbf840001, 0xbf810000,
	0x8778ff78, 0x00002000,
	0x80ec886c, 0x82ed806d,
	0xb8eef807, 0x866fff6e,
	0x001f8000, 0x8e6f8b6f,
	0x8977ff77, 0xfc000000,
	0x87776f77, 0x896eff6e,
	0x001f8000, 0xb96ef807,
	0xb8f0f812, 0xb8f1f813,
	0x8ef08870, 0xc0071bb8,
	0x00000000, 0xbf8cc07f,
	0xc0071c38, 0x00000008,
	0xbf8cc07f, 0x86ee6e6e,
	0xbf840001, 0xbe801d6e,
	0xb8f1f803, 0x8671ff71,
	0x000001ff, 0xbf850002,
	0x806c846c, 0x826d806d,
	0x866dff6d, 0x0000ffff,
	0x8f6e8b77, 0x866eff6e,
	0x001f8000, 0xb96ef807,
	0x86fe7e7e, 0x86ea6a6a,
	0xb978f802, 0xbe801f6c,
	0x866dff6d, 0x0000ffff,
	0xbef00080, 0xb9700283,
	0xb8f02407, 0x8e709c70,
	0x876d706d, 0xb8f003c7,
	0x8e709b70, 0x876d706d,
	0xb8f0f807, 0x8670ff70,
	0x00007fff, 0xb970f807,
	0xbeee007e, 0xbeef007f,
	0xbefe0180, 0xbf900004,
	0x87708478, 0xb970f802,
	0xbf8e0002, 0xbf88fffe,
	0xb8f02a05, 0x80708170,
	0x8e708a70, 0xb8f11605,
	0x80718171, 0x8e718671,
	0x80707170, 0x80707e70,
	0x8271807f, 0x8671ff71,
	0x0000ffff, 0xc0471cb8,
	0x00000040, 0xbf8cc07f,
	0xc04b1d38, 0x00000048,
	0xbf8cc07f, 0xc0431e78,
	0x00000058, 0xbf8cc07f,
	0xc0471eb8, 0x0000005c,
	0xbf8cc07f, 0xbef4007e,
	0x8675ff7f, 0x0000ffff,
	0x8775ff75, 0x00040000,
	0xbef60080, 0xbef700ff,
	0x00807fac, 0x8670ff7f,
	0x08000000, 0x8f708370,
	0x87777077, 0x8670ff7f,
	0x70000000, 0x8f708170,
	0x87777077, 0xbefb007c,
	0xbefa0080, 0xb8fa2a05,
	0x807a817a, 0x8e7a8a7a,
	0xb8f01605, 0x80708170,
	0x8e708670, 0x807a707a,
	0xbef60084, 0xbef600ff,
	0x01000000, 0xbefe007c,
	0xbefc007a, 0xc0611efa,
	0x0000007c, 0xbf8cc07f,
	0x807a847a, 0xbefc007e,
	0xbefe007c, 0xbefc007a,
	0xc0611b3a, 0x0000007c,
	0xbf8cc07f, 0x807a847a,
	0xbefc007e, 0xbefe007c,
	0xbefc007a, 0xc0611b7a,
	0x0000007c, 0xbf8cc07f,
	0x807a847a, 0xbefc007e,
	0xbefe007c, 0xbefc007a,
	0xc0611bba, 0x0000007c,
	0xbf8cc07f, 0x807a847a,
	0xbefc007e, 0xbefe007c,
	0xbefc007a, 0xc0611bfa,
	0x0000007c, 0xbf8cc07f,
	0x807a847a, 0xbefc007e,
	0xbefe007c, 0xbefc007a,
	0xc0611e3a, 0x0000007c,
	0xbf8cc07f, 0x807a847a,
	0xbefc007e, 0xb8f1f803,
	0xbefe007c, 0xbefc007a,
	0xc0611c7a, 0x0000007c,
	0xbf8cc07f, 0x807a847a,
	0xbefc007e, 0xbefe007c,
	0xbefc007a, 0xc0611a3a,
	0x0000007c, 0xbf8cc07f,
	0x807a847a, 0xbefc007e,
	0xbefe007c, 0xbefc007a,
	0xc0611a7a, 0x0000007c,
	0xbf8cc07f, 0x807a847a,
	0xbefc007e, 0xb8fbf801,
	0xbefe007c, 0xbefc007a,
	0xc0611efa, 0x0000007c,
	0xbf8cc07f, 0x807a847a,
	0xbefc007e, 0x8670ff7f,
	0x04000000, 0xbeef0080,
	0x876f6f70, 0xb8fa2a05,
	0x807a817a, 0x8e7a8a7a,
	0xb8f11605, 0x80718171,
	0x8e718471, 0x8e768271,
	0xbef600ff, 0x01000000,
	0xbef20174, 0x80747a74,
	0x82758075, 0xbefc0080,
	0xbf800000, 0xbe802b00,
	0xbe822b02, 0xbe842b04,
	0xbe862b06, 0xbe882b08,
	0xbe8a2b0a, 0xbe8c2b0c,
	0xbe8e2b0e, 0xc06b003a,
	0x00000000, 0xbf8cc07f,
	0xc06b013a, 0x00000010,
	0xbf8cc07f, 0xc06b023a,
	0x00000020, 0xbf8cc07f,
	0xc06b033a, 0x00000030,
	0xbf8cc07f, 0x8074c074,
	0x82758075, 0x807c907c,
	0xbf0a717c, 0xbf85ffe7,
	0xbef40172, 0xbefa0080,
	0xbefe00c1, 0xbeff00c1,
	0xbee80080, 0xbee90080,
	0xbef600ff, 0x01000000,
	0xe0724000, 0x7a1d0000,
	0xe0724100, 0x7a1d0100,
	0xe0724200, 0x7a1d0200,
	0xe0724300, 0x7a1d0300,
	0xbefe00c1, 0xbeff00c1,
	0xb8f14306, 0x8671c171,
	0xbf84002c, 0xbf8a0000,
	0x8670ff6f, 0x04000000,
	0xbf840028, 0x8e718671,
	0x8e718271, 0xbef60071,
	0xb8fa2a05, 0x807a817a,
	0x8e7a8a7a, 0xb8f01605,
	0x80708170, 0x8e708670,
	0x807a707a, 0x807aff7a,
	0x00000080, 0xbef600ff,
	0x01000000, 0xbefc0080,
	0xd28c0002, 0x000100c1,
	0xd28d0003, 0x000204c1,
	0xd1060002, 0x00011103,
	0x7e0602ff, 0x00000200,
	0xbefc00ff, 0x00010000,
	0xbe800077, 0x8677ff77,
	0xff7fffff, 0x8777ff77,
	0x00058000, 0xd8ec0000,
	0x00000002, 0xbf8cc07f,
	0xe0765000, 0x7a1d0002,
	0x68040702, 0xd0c9006a,
	0x0000e302, 0xbf87fff7,
	0xbef70000, 0xbefa00ff,
	0x00000400, 0xbefe00c1,
	0xbeff00c1, 0xb8f12a05,
	0x80718171, 0x8e718271,
	0x8e768871, 0xbef600ff,
	0x01000000, 0xbefc0084,
	0xbf0a717c, 0xbf840015,
	0xbf11017c, 0x8071ff71,
	0x00001000, 0x7e000300,
	0x7e020301, 0x7e040302,
	0x7e060303, 0xe0724000,
	0x7a1d0000, 0xe0724100,
	0x7a1d0100, 0xe0724200,
	0x7a1d0200, 0xe0724300,
	0x7a1d0300, 0x807c847c,
	0x807aff7a, 0x00000400,
	0xbf0a717c, 0xbf85ffef,
	0xbf9c0000, 0xbf8200d9,
	0xbef4007e, 0x8675ff7f,
	0x0000ffff, 0x8775ff75,
	0x00040000, 0xbef60080,
	0xbef700ff, 0x00807fac,
	0x866eff7f, 0x08000000,
	0x8f6e836e, 0x87776e77,
	0x866eff7f, 0x70000000,
	0x8f6e816e, 0x87776e77,
	0x866eff7f, 0x04000000,
	0xbf84001e, 0xbefe00c1,
	0xbeff00c1, 0xb8ef4306,
	0x866fc16f, 0xbf840019,
	0x8e6f866f, 0x8e6f826f,
	0xbef6006f, 0xb8f82a05,
	0x80788178, 0x8e788a78,
	0xb8ee1605, 0x806e816e,
	0x8e6e866e, 0x80786e78,
	0x8078ff78, 0x00000080,
	0xbef600ff, 0x01000000,
	0xbefc0080, 0xe0510000,
	0x781d0000, 0xe0510100,
	0x781d0000, 0x807cff7c,
	0x00000200, 0x8078ff78,
	0x00000200, 0xbf0a6f7c,
	0xbf85fff6, 0xbef80080,
	0xbefe00c1, 0xbeff00c1,
	0xb8ef2a05, 0x806f816f,
	0x8e6f826f, 0x8e76886f,
	0xbef600ff, 0x01000000,
	0xbeee0078, 0x8078ff78,
	0x00000400, 0xbefc0084,
	0xbf11087c, 0x806fff6f,
	0x00008000, 0xe0524000,
	0x781d0000, 0xe0524100,
	0x781d0100, 0xe0524200,
	0x781d0200, 0xe0524300,
	0x781d0300, 0xbf8c0f70,
	0x7e000300, 0x7e020301,
	0x7e040302, 0x7e060303,
	0x807c847c, 0x8078ff78,
	0x00000400, 0xbf0a6f7c,
	0xbf85ffee, 0xbf9c0000,
	0xe0524000, 0x6e1d0000,
	0xe0524100, 0x6e1d0100,
	0xe0524200, 0x6e1d0200,
	0xe0524300, 0x6e1d0300,
	0xb8f82a05, 0x80788178,
	0x8e788a78, 0xb8ee1605,
	0x806e816e, 0x8e6e866e,
	0x80786e78, 0x80f8c078,
	0xb8ef1605, 0x806f816f,
	0x8e6f846f, 0x8e76826f,
	0xbef600ff, 0x01000000,
	0xbefc006f, 0xc031003a,
	0x00000078, 0x80f8c078,
	0xbf8cc07f, 0x80fc907c,
	0xbf800000, 0xbe802d00,
	0xbe822d02, 0xbe842d04,
	0xbe862d06, 0xbe882d08,
	0xbe8a2d0a, 0xbe8c2d0c,
	0xbe8e2d0e, 0xbf06807c,
	0xbf84fff0, 0xb8f82a05,
	0x80788178, 0x8e788a78,
	0xb8ee1605, 0x806e816e,
	0x8e6e866e, 0x80786e78,
	0xbef60084, 0xbef600ff,
	0x01000000, 0xc0211bfa,
	0x00000078, 0x80788478,
	0xc0211b3a, 0x00000078,
	0x80788478, 0xc0211b7a,
	0x00000078, 0x80788478,
	0xc0211eba, 0x00000078,
	0x80788478, 0xc0211efa,
	0x00000078, 0x80788478,
	0xc0211c3a, 0x00000078,
	0x80788478, 0xc0211c7a,
	0x00000078, 0x80788478,
	0xc0211a3a, 0x00000078,
	0x80788478, 0xc0211a7a,
	0x00000078, 0x80788478,
	0xc0211cfa, 0x00000078,
	0x80788478, 0xbf8cc07f,
	0xbefc006f, 0xbefe007a,
	0xbeff007b, 0x866f71ff,
	0x000003ff, 0xb96f4803,
	0x866f71ff, 0xfffff800,
	0x8f6f8b6f, 0xb96fa2c3,
	0xb973f801, 0xb8ee2a05,
	0x806e816e, 0x8e6e8a6e,
	0xb8ef1605, 0x806f816f,
	0x8e6f866f, 0x806e6f6e,
	0x806e746e, 0x826f8075,
	0x866fff6f, 0x0000ffff,
	0xc0071cb7, 0x00000040,
	0xc00b1d37, 0x00000048,
	0xc0031e77, 0x00000058,
	0xc0071eb7, 0x0000005c,
	0xbf8cc07f, 0x866fff6d,
	0xf0000000, 0x8f6f9c6f,
	0x8e6f906f, 0xbeee0080,
	0x876e6f6e, 0x866fff6d,
	0x08000000, 0x8f6f9b6f,
	0x8e6f8f6f, 0x876e6f6e,
	0x866fff70, 0x00800000,
	0x8f6f976f, 0xb96ef807,
	0x866dff6d, 0x0000ffff,
	0x86fe7e7e, 0x86ea6a6a,
	0xb970f802, 0xbf8a0000,
	0x95806f6c, 0xbf810000,
};
