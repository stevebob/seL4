/*
 * Copyright 2016, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#ifndef __KERNEL_X86_TRAPS_H
#define __KERNEL_X86_TRAPS_H

#include <config.h>
#include <util.h>

static inline void arch_c_entry_hook(void)
{
#ifdef CONFIG_FSGSBASE_INST
    tcb_t *tcb = NODE_STATE(ksCurThread);
    x86_save_fsgs_base(tcb, SMP_TERNARY(getCurrentCPUIndex(), 0));
#endif
}

static inline void arch_c_exit_hook(void)
{
    /* Restore the values ofthe FS and GS base. */
    tcb_t *tcb = NODE_STATE(ksCurThread);
    x86_load_fsgs_base(tcb,  SMP_TERNARY(getCurrentCPUIndex(), 0));
}

#ifdef CONFIG_KERNEL_MCS
void c_handle_syscall(word_t cptr, word_t msgInfo, syscall_t syscall, word_t reply)
#else
void c_handle_syscall(word_t cptr, word_t msgInfo, syscall_t syscall)
#endif
VISIBLE NORETURN;

void restore_user_context(void)
VISIBLE NORETURN;

void c_nested_interrupt(int irq)
VISIBLE;

void c_handle_interrupt(int irq, int syscall)
VISIBLE NORETURN;

void c_handle_vmexit(void)
VISIBLE NORETURN;

#endif /* __KERNEL_X86_TRAPS_H */
