// SPDX-License-Identifier: GPL-2.0-only
/*
 *  linux/lib/vsprintf.c
 *
 *  Copyright (C) 1991, 1992  Linus Torvalds
 */
typedef unsigned long size_t;

const char *_parse_integer_fixup_radix(const char *s, unsigned int *base);
unsigned int _parse_integer_limit(const char *s, unsigned int base, unsigned long long *res,
      size_t max_chars);
unsigned int _parse_integer(const char *s, unsigned int base, unsigned long long *res);

unsigned long long simple_strntoull(const char *startp, char **endp, unsigned int base, size_t max_chars);

unsigned long long simple_strntoull(const char *startp, char **endp, unsigned int base, size_t max_chars)
{
 const char *cp;
 unsigned long long result = 0ULL;
 size_t prefix_chars;
 unsigned int rv;

 cp = _parse_integer_fixup_radix(startp, &base);
 prefix_chars = cp - startp;
 if (prefix_chars < max_chars) {
  rv = _parse_integer_limit(cp, base, &result, max_chars - prefix_chars);

  cp += (rv & ~(1U << 31));
 } else {

  cp = startp + max_chars;
 }

 if (endp)
  *endp = (char *)cp;

 return result;
}
