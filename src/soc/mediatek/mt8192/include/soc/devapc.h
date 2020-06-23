/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef SOC_MEDIATEK_MT8192_DEVAPC_H
#define SOC_MEDIATEK_MT8192_DEVAPC_H

#include <device/mmio.h>
#include <soc/addressmap.h>

void dapc_init(void);

#define DEVAPC_AO_MAX 6

enum devapc_ao_offset {
	MAS_DOM_0 = 0x0900,
	MAS_DOM_1 = 0x0904,
	MAS_SEC_0 = 0x0A00,
	AO_APC_CON = 0x0F00,
};

/* INFRA */
DEFINE_BIT(SCP_SSPM_SEC, 3)
DEFINE_BIT(CPU_EB_SEC, 4)

DEFINE_BITFIELD(PCIE_DOM, 19, 16)		/* 2 */
DEFINE_BITFIELD(SCP_SSPM_DOM, 3, 0)		/* 4 */
DEFINE_BITFIELD(CPU_EB_DOM, 11, 8)		/* 5 */

/* PERI */
DEFINE_BITFIELD(SPM_DOM, 3, 0)		/* 0 */

enum master_domain {
	MAS_DOMAIN_0 = 0,
	MAS_DOMAIN_1,
	MAS_DOMAIN_2,
	MAS_DOMAIN_3,
	MAS_DOMAIN_4,
	MAS_DOMAIN_5,
	MAS_DOMAIN_6,
	MAS_DOMAIN_7,
	MAS_DOMAIN_8,
	MAS_DOMAIN_9,
	MAS_DOMAIN_10,
	MAS_DOMAIN_11,
	MAS_DOMAIN_12,
	MAS_DOMAIN_13,
	MAS_DOMAIN_14,
	MAS_DOMAIN_15,
	MAS_DOMAIN_MAX,
};


#endif /* SOC_MEDIATEK_MT8192_DEVAPC_H */