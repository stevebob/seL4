/*
 * Copyright 2014, General Dynamics C4 Systems
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

#ifndef __MACHINE_IO_H_
#define __MACHINE_IO_H_

#include <config.h>
#include <util.h>
#include <arch/types.h>

#define FORMAT(archetype, string_index, first_to_check) \
        __attribute__((format(archetype, string_index, first_to_check)))

#if (defined CONFIG_DEBUG_BUILD) || (defined CONFIG_PRINTING)
void putDebugChar(unsigned char c);
#endif

#ifdef CONFIG_DEBUG_BUILD
/* io for dumping capdl */
unsigned char getDebugChar(void);
#endif

#ifdef CONFIG_PRINTING
/* printf will result in output */
void putchar(char c);
#define kernel_putchar(c) putchar(c)
word_t kprintf(const char *format, ...) VISIBLE FORMAT(printf, 1, 2);
word_t puts(const char *s) VISIBLE;
word_t print_unsigned_long(unsigned long x, word_t ui_base) VISIBLE;
#define printf(args...) kprintf(args)
#else /* CONFIG_PRINTING */
/* printf will NOT result in output */
#define kernel_putchar(c) ((void)(0))
#define printf(args...) ((void)(0))
#define puts(s) ((void)(0))
#endif /* CONFIG_PRINTING */

#endif /* __MACHINE_IO_H_ */
