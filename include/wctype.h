/*-
 * Copyright (c)1999 Citrus Project,
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	citrus Id: wctype.h,v 1.4 2000/12/21 01:50:21 itojun Exp
 *	$NetBSD: wctype.h,v 1.3 2000/12/22 14:16:16 itojun Exp $
 * $FreeBSD: /repoman/r/ncvs/src/include/wctype.h,v 1.10 2002/08/21 16:19:55 mike Exp $
 */

#ifndef _WCTYPE_H_
#define	_WCTYPE_H_

#include <sys/cdefs.h>
#include <_types.h>
#include <ctype.h>

#ifndef	_BSD_CT_RUNE_T_DEFINED_
#define _BSD_CT_RUNE_T_DEFINED_
typedef	__osx_ct_rune_t	ct_rune_t;
#endif

#ifndef	_BSD_RUNE_T_DEFINED_
#define _BSD_RUNE_T_DEFINED_
typedef	__osx_rune_t	rune_t;
#endif

#ifndef	__cplusplus
#ifndef	_BSD_WCHAR_T_DEFINED_
#define	_BSD_WCHAR_T_DEFINED_
typedef	__osx_wchar_t	wchar_t;
#endif	/* _BSD_WCHAR_T_DEFINED_ */
#endif	/* __cplusplus */

#ifndef	_BSD_WINT_T_DEFINED_
#define _BSD_WINT_T_DEFINED_
typedef	__osx_wint_t	wint_t;
#endif

#ifndef _WCTRANS_T_DEFINED_
#define	_WCTRANS_T_DEFINED_
typedef	__osx_wctrans_t	wctrans_t;
#endif

#ifndef _WCTYPE_T_DEFINED_
#define	_WCTYPE_T_DEFINED_
typedef	__osx_wctype_t	wctype_t;
#endif

#ifndef WEOF
#define	WEOF		__OSX_WEOF
#endif

__BEGIN_DECLS
int	iswalnum(wint_t);
int	iswalpha(wint_t);
int	iswblank(wint_t);
int	iswcntrl(wint_t);
int	iswctype(wint_t, wctype_t);
int	iswdigit(wint_t);
int	iswgraph(wint_t);
int	iswlower(wint_t);
int	iswprint(wint_t);
int	iswpunct(wint_t);
int	iswspace(wint_t);
int	iswupper(wint_t);
int	iswxdigit(wint_t);
wint_t	towctrans(wint_t, wctrans_t);
wint_t	towlower(wint_t);
wint_t	towupper(wint_t);
wctrans_t
	wctrans(const char *);
wctype_t
	wctype(const char *);

#if !defined(_ANSI_SOURCE)
wint_t	iswascii(wint_t);
wint_t	iswhexnumber(wint_t);
wint_t	iswideogram(wint_t);
wint_t	iswnumber(wint_t);
wint_t	iswphonogram(wint_t);
wint_t	iswrune(wint_t);
wint_t	iswspecial(wint_t);
#endif
__END_DECLS

#define	iswalnum(wc)		__istype((wc), _CTYPE_A|_CTYPE_D)
#define	iswalpha(wc)		__istype((wc), _CTYPE_A)
#define	iswblank(wc)		__istype((wc), _CTYPE_B)
#define	iswcntrl(wc)		__istype((wc), _CTYPE_C)
#define	iswctype(wc, charclass)	__istype((wc), (charclass))
#define	iswdigit(wc)		__istype((wc), _CTYPE_D)
#define	iswgraph(wc)		__istype((wc), _CTYPE_G)
#define	iswlower(wc)		__istype((wc), _CTYPE_L)
#define	iswprint(wc)		__istype((wc), _CTYPE_R)
#define	iswpunct(wc)		__istype((wc), _CTYPE_P)
#define	iswspace(wc)		__istype((wc), _CTYPE_S)
#define	iswupper(wc)		__istype((wc), _CTYPE_U)
#define	iswxdigit(wc)		__istype((wc), _CTYPE_X)
#define	towlower(wc)		__tolower(wc)
#define	towupper(wc)		__toupper(wc)

#if !defined(_ANSI_SOURCE)
#define	iswascii(wc)		(((wc) & ~0x7F) == 0)
#define	iswhexnumber(wc)	__istype((wc), _CTYPE_X)
#define	iswideogram(wc)		__istype((wc), _CTYPE_I)
#define	iswnumber(wc)		__istype((wc), _CTYPE_D)
#define	iswphonogram(wc)	__istype((wc), _CTYPE_Q)
#define	iswrune(wc)		__istype((wc), 0xFFFFFF00L)
#define	iswspecial(wc)		__istype((wc), _CTYPE_T)
#endif

#endif		/* _WCTYPE_H_ */
