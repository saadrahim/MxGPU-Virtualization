/*
 * Copyright (c) 2020-2021 Advanced Micro Devices, Inc. All rights reserved.
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

#ifndef AMDGV_ASIC_H
#define AMDGV_ASIC_H

#define AMDGV_FW_SIZE_MAX (1024 * 1024) /* 1M */
/*
 * Supported ASIC types
 * Use explicit assignment to avoid unintetional change of index value
 */
enum amd_asic_type {
	CHIP_MI300X = 9,
	CHIP_MI308X = 11,
	CHIP_LAST,

	CHIP_NOT_SUPPORTED = 0xFFFFFFFF
};

enum amdgv_firmware_id {
	AMDGV_FIRMWARE_ID__SMU = 1,
	AMDGV_FIRMWARE_ID__CP_CE,
	AMDGV_FIRMWARE_ID__CP_PFP,
	AMDGV_FIRMWARE_ID__CP_ME,
	AMDGV_FIRMWARE_ID__CP_MEC_JT1,
	AMDGV_FIRMWARE_ID__CP_MEC_JT2,
	AMDGV_FIRMWARE_ID__CP_MEC1,
	AMDGV_FIRMWARE_ID__CP_MEC2,
	AMDGV_FIRMWARE_ID__RLC,
	AMDGV_FIRMWARE_ID__SDMA0,
	AMDGV_FIRMWARE_ID__SDMA1,
	AMDGV_FIRMWARE_ID__SDMA2,
	AMDGV_FIRMWARE_ID__SDMA3,
	AMDGV_FIRMWARE_ID__SDMA4,
	AMDGV_FIRMWARE_ID__SDMA5,
	AMDGV_FIRMWARE_ID__SDMA6,
	AMDGV_FIRMWARE_ID__SDMA7,
	AMDGV_FIRMWARE_ID__VCN,
	AMDGV_FIRMWARE_ID__UVD,
	AMDGV_FIRMWARE_ID__VCE,
	AMDGV_FIRMWARE_ID__ISP,
	AMDGV_FIRMWARE_ID__DMCU_ERAM,
	AMDGV_FIRMWARE_ID__DMCU_ISR,
	AMDGV_FIRMWARE_ID__RLC_RESTORE_LIST_GPM_MEM,
	AMDGV_FIRMWARE_ID__RLC_RESTORE_LIST_SRM_MEM,
	AMDGV_FIRMWARE_ID__RLC_RESTORE_LIST_CNTL,
	AMDGV_FIRMWARE_ID__RLC_V,
	AMDGV_FIRMWARE_ID__RLC_P,
	AMDGV_FIRMWARE_ID__MMSCH,
	AMDGV_FIRMWARE_ID__PSP_SYS,
	AMDGV_FIRMWARE_ID__PSP_SOS,
	AMDGV_FIRMWARE_ID__PSP_TOC,
	AMDGV_FIRMWARE_ID__PSP_KEYDB,
	AMDGV_FIRMWARE_ID__DFC_FW,
	AMDGV_FIRMWARE_ID__PSP_BL,
	AMDGV_FIRMWARE_ID__PSP_SPL,
	AMDGV_FIRMWARE_ID__DRV_CAP,
	AMDGV_FIRMWARE_ID__SEC_POLICY_STAGE2,
	AMDGV_FIRMWARE_ID__REG_ACCESS_WHITELIST,
	AMDGV_FIRMWARE_ID__IMU_DRAM,
	AMDGV_FIRMWARE_ID__IMU_IRAM,
	AMDGV_FIRMWARE_ID__SDMA_UCODE_TH0,
	AMDGV_FIRMWARE_ID__SDMA_UCODE_TH1,
	AMDGV_FIRMWARE_ID__CP_MES,
	AMDGV_FIRMWARE_ID__MES_STACK,
	AMDGV_FIRMWARE_ID__MES_THREAD1,
	AMDGV_FIRMWARE_ID__MES_THREAD1_STACK,
	AMDGV_FIRMWARE_ID__RLX6,
	AMDGV_FIRMWARE_ID__RLX6_DRAM_BOOT,
	AMDGV_FIRMWARE_ID__RS64_ME_UCODE,
	AMDGV_FIRMWARE_ID__RS64_ME_P0_DATA,
	AMDGV_FIRMWARE_ID__RS64_ME_P1_DATA,
	AMDGV_FIRMWARE_ID__RS64_PFP_UCODE,
	AMDGV_FIRMWARE_ID__RS64_PFP_P0_DATA,
	AMDGV_FIRMWARE_ID__RS64_PFP_P1_DATA,
	AMDGV_FIRMWARE_ID__RS64_MEC_UCODE,
	AMDGV_FIRMWARE_ID__RS64_MEC_P0_DATA,
	AMDGV_FIRMWARE_ID__RS64_MEC_P1_DATA,
	AMDGV_FIRMWARE_ID__RS64_MEC_P2_DATA,
	AMDGV_FIRMWARE_ID__RS64_MEC_P3_DATA,
	AMDGV_FIRMWARE_ID__PPTABLE,
	AMDGV_FIRMWARE_ID__P2S_TABLE,
	AMDGV_FIRMWARE_ID__PSP_SOC,
	AMDGV_FIRMWARE_ID__PSP_DBG,
	AMDGV_FIRMWARE_ID__PSP_INTF,
	AMDGV_FIRMWARE_ID__RLX6_UCODE_CORE1,
	AMDGV_FIRMWARE_ID__RLX6_DRAM_BOOT_CORE1,

	/*temp defs for direct loading*/
	AMDGV_FIRMWARE_ID__RLCV_LX7,
	AMDGV_FIRMWARE_ID__RLC_SAVE_RESTROE_LIST,
	AMDGV_FIRMWARE_ID__PSP_RAS,
	AMDGV_FIRMWARE_ID__RAS_TA,

	AMDGV_FIRMWARE_ID__MAX
};

#endif
