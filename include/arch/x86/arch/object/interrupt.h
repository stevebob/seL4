/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#ifndef __ARCH_OBJECT_INTERRUPT_H
#define __ARCH_OBJECT_INTERRUPT_H

#include <types.h>
#include <api/failures.h>
#include <object/structures.h>
#include <plat/machine.h>

exception_t Arch_decodeIRQControlInvocation(word_t invLabel, word_t length,
                                            cte_t *srcSlot, extra_caps_t excaps,
                                            word_t *buffer);
void Arch_irqStateInit(void);
exception_t Arch_checkIRQ(word_t irq_w);

#endif
