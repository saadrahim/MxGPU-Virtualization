/*
 * Copyright (c) 2008-2021 Advanced Micro Devices, Inc. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef ATOM_H
#define ATOM_H

#include "amdgv_oss_wrapper.h"

#define ATOM_BIOS_MAGIC		 0xAA55
#define ATOM_ATI_MAGIC_PTR	 0x30
#define ATOM_ATI_MAGIC		 " 761295520"
#define ATOM_ROM_TABLE_PTR	 0x48
#define ATOM_ROM_PART_NUMBER_PTR 0x6E

#define ATOM_ROM_MAGIC	   "ATOM"
#define ATOM_ROM_MAGIC_PTR 4

#define ATOM_ROM_CMD_PTR  0x1E
#define ATOM_ROM_DATA_PTR 0x20

#define ATOM_DATA_IIO_PTR 0x32

#define ATOM_CT_SIZE_PTR 0
#define ATOM_CT_WS_PTR	 4
#define ATOM_CT_PS_PTR	 5
#define ATOM_CT_PS_MASK	 0x7F
#define ATOM_CT_CODE_PTR 6

#define ATOM_OP_CNT 127
#define ATOM_OP_EOT 91

#define ATOM_CASE_MAGIC 0x63
#define ATOM_CASE_END	0x5A5A

#define ATOM_ARG_REG 0
#define ATOM_ARG_PS  1
#define ATOM_ARG_WS  2
#define ATOM_ARG_FB  3
#define ATOM_ARG_ID  4
#define ATOM_ARG_IMM 5
#define ATOM_ARG_PLL 6
#define ATOM_ARG_MC  7

#define ATOM_SRC_DWORD	0
#define ATOM_SRC_WORD0	1
#define ATOM_SRC_WORD8	2
#define ATOM_SRC_WORD16 3
#define ATOM_SRC_BYTE0	4
#define ATOM_SRC_BYTE8	5
#define ATOM_SRC_BYTE16 6
#define ATOM_SRC_BYTE24 7

#define ATOM_WS_QUOTIENT   0x40
#define ATOM_WS_REMAINDER  0x41
#define ATOM_WS_DATAPTR	   0x42
#define ATOM_WS_SHIFT	   0x43
#define ATOM_WS_OR_MASK	   0x44
#define ATOM_WS_AND_MASK   0x45
#define ATOM_WS_FB_WINDOW  0x46
#define ATOM_WS_ATTRIBUTES 0x47
#define ATOM_WS_REGPTR	   0x48

#define ATOM_IIO_NOP	    0
#define ATOM_IIO_START	    1
#define ATOM_IIO_READ	    2
#define ATOM_IIO_WRITE	    3
#define ATOM_IIO_CLEAR	    4
#define ATOM_IIO_SET	    5
#define ATOM_IIO_MOVE_INDEX 6
#define ATOM_IIO_MOVE_ATTR  7
#define ATOM_IIO_MOVE_DATA  8
#define ATOM_IIO_END	    9

#define ATOM_IO_MM    0
#define ATOM_IO_PCI   1
#define ATOM_IO_SYSIO 2
#define ATOM_IO_IIO   0x80

#define AMDGV_ATOM_EXECUTE_TIMEOUT 5000000

struct card_info {
	struct amdgv_adapter *dev;
	void (*reg_write)(struct card_info *, uint32_t, uint32_t);
	uint32_t (*reg_read)(struct card_info *, uint32_t);
	void (*ioreg_write)(struct card_info *, uint32_t, uint32_t);
	uint32_t (*ioreg_read)(struct card_info *, uint32_t);
	void (*mc_write)(struct card_info *, uint32_t, uint32_t);
	uint32_t (*mc_read)(struct card_info *, uint32_t);
	void (*pll_write)(struct card_info *, uint32_t, uint32_t);
	uint32_t (*pll_read)(struct card_info *, uint32_t);
	void (*fb_write)(struct card_info *, uint64_t, uint32_t);
	uint32_t (*fb_read)(struct card_info *, uint64_t);
};

struct atom_context {
	struct card_info *card;
	mutex_t mutex;
	void *bios;
	uint32_t cmd_table, data_table;
	uint16_t *iio;

	uint16_t data_block;
	uint32_t fb_base;
	uint32_t divmul[2];
	uint16_t io_attr;
	uint16_t reg_block;
	uint8_t shift;
	int cs_equal, cs_above;
	int io_mode;
	uint32_t post_type;
};

extern int amdgv_atom_debug;

bool amdgv_atom_parse(struct atom_context *, void *);
int amdgv_atom_execute_table(struct atom_context *, int, uint32_t *);
bool amdgv_atom_parse_data_header(struct atom_context *ctx, int index, uint16_t *size,
				  uint8_t *frev, uint8_t *crev, uint16_t *data_start);
bool amdgv_atom_parse_cmd_header(struct atom_context *ctx, int index, uint8_t *frev,
				 uint8_t *crev, uint16_t *data_start);

#include "atom-types.h"

#endif
