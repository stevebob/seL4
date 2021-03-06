/*
 * Copyright 2020, Data61, CSIRO (ABN 41 687 119 230)
 *
 * SPDX-License-Identifier: GPL-2.0-only
 */

/*
 *
 */

#ifndef __ARCH_API_TYPES
#define __ARCH_API_TYPES

#include <config.h>
#include <sel4/objecttype.h>
#include <sel4/sel4_arch/objecttype.h>
#include <sel4/arch/objecttype.h>


#define pageType PageObject4K

enum asidConstants {
    asidInvalid = 0
};

#define asidMax (BIT(asidLowBits + asidHighBits) - 1)

typedef word_t asid_t;

#endif
