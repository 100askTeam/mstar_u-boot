/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (c) 2020 Daniel Palmer<daniel@thingy.jp>
 */

#ifndef __MSTARV7_CONFIG_H
#define __MSTARV7_CONFIG_H

#include "../../arch/arm/mach-mstar/include/mstarv7.h"

#define CONFIG_SYS_UBOOT_BASE		0 // for spl_nor

#define CONFIG_SYS_SPI_U_BOOT_OFFS	0x20000

#define CONFIG_SYS_SDRAM_BASE		0x20000000

#ifdef CONFIG_MSTAR_INFINITY1
#define MSTAR_SRAM_SZ			0x16000 // If i1 is selected there is only 88KB
#else
#define MSTAR_SRAM_SZ			0x20000 // i3+ seem to have 128KB
#endif

#define CONFIG_SPL_MAX_SIZE		CONFIG_SPL_SIZE_LIMIT

#define CONFIG_SPL_STACK		(MSTAR_SRAM + MSTAR_SRAM_SZ)

#define CONFIG_SPL_BSS_START_ADDR	MSTAR_SRAM + CONFIG_SPL_MAX_SIZE
#define CONFIG_SPL_BSS_MAX_SIZE		0x4000

#define CONFIG_SYS_HZ_CLOCK 6000000
#define CONFIG_ENV_SIZE			0x2000
#define CONFIG_ENV_OFFSET		0x2000 // 8KB into the rom partition, just in case we need to put something at the start
#define CONFIG_ENV_SECT_SIZE		4096

#define CONFIG_SYS_MMCSD_FS_BOOT_PARTITION	1
#define CONFIG_SPL_FS_LOAD_PAYLOAD_NAME	"u-boot.img"

#endif
