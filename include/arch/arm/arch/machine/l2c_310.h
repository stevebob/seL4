/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

/*
 * ARM L2 Cache controller L2C-310
 */

#ifndef __ARCH_MACHINE_L2C_310_H
#define __ARCH_MACHINE_L2C_310_H

#include <arch/types.h>


void initL2Cache(void);

void plat_cleanInvalidateL2Cache(void);
void plat_cleanCache(void);
void plat_cleanL2Range(paddr_t start, paddr_t end);
void plat_invalidateL2Range(paddr_t start, paddr_t end);
void plat_cleanInvalidateL2Range(paddr_t start, paddr_t end);

#endif /* !__ARCH_MACHINE_L2C_310_H */
