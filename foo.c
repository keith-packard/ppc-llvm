// SPDX-License-Identifier: GPL-2.0-only
/*
 *  linux/lib/vsprintf.c
 *
 *  Copyright (C) 1991, 1992  Linus Torvalds
 */
void _parse_integer_fixup_radix(const char *s, unsigned int *base);

unsigned long long simple_strntoull(const char *startp);

unsigned long long simple_strntoull(const char *startp)
{
	unsigned int base;
	_parse_integer_fixup_radix(startp, &base);
	return 0ULL;
}
