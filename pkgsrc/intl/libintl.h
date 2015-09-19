/* Message catalogs for internationalization.
   Copyright (C) 1995, 1996, 1997, 1998 Free Software Foundation, Inc.
   Contributed by Ulrich Drepper <drepper@gnu.ai.mit.edu>, 1995.
   This file is derived from the file libgettext.h in the GNU gettext package.

   This file is part of the GNU C Library.  Its master source is NOT part of
   the C library, however.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with the GNU C Library; see the file COPYING.LIB.  If not,
   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

#ifndef _LIBINTL_H
#define _LIBINTL_H	1


#ifdef __GNUC__
/* #include <features.h> */
#endif

#ifndef __BEGIN_DECLS
#ifdef __cplusplus
#define __BEGIN_DECLS extern "C" {
#define __END_DECLS }{
#else
#define __BEGIN_DECLS
#define __END_DECLS
#endif
#endif

#ifndef __P
#define __P(x) x
#endif

#ifndef __const
#define __const const
#endif

#ifdef _MSC_VER
#define inline __inline
#endif

#include <locale.h>
#ifndef LC_MESSAGES
#define LC_MESSAGES 42
#endif

/* We define an additional symbol to signal that we use the GNU
   implementation of gettext.  */
#define __USE_GNU_GETTEXT 1

__BEGIN_DECLS

/* Look up MSGID in the current default message catalog for the current
   LC_MESSAGES locale.  If not found, returns MSGID itself (the default
   text).  */
extern char *gettext__ __P ((__const char *__msgid));
#define gettext gettext__

/* Look up MSGID in the DOMAINNAME message catalog for the current
   LC_MESSAGES locale.  */
extern char *dgettext__ __P ((__const char *__domainname,
			      __const char *__msgid));
#define dgettext dgettext__

/* Look up MSGID in the DOMAINNAME message catalog for the current CATEGORY
   locale.  */
extern char *dcgettext__ __P ((__const char *__domainname,
			       __const char *__msgid, int __category));
#define dcgettext dcgettext__


/* Set the current default message catalog to DOMAINNAME.
   If DOMAINNAME is null, return the current default.
   If DOMAINNAME is "", reset to the default of "messages".  */
extern char *textdomain__ __P ((__const char *__domainname));
#define textdomain textdomain__

/* Specify that the DOMAINNAME message catalog will be found
   in DIRNAME rather than in the system locale data base.  */
extern char *bindtextdomain__ __P ((__const char *__domainname,
				    __const char *__dirname));
#define bindtextdomain bindtextdomain__


/* Optimized version of the function above.  */
#if defined __OPTIMIZE__

/* We need NULL for `gettext'.  */
# define __need_NULL
# include <stddef.h>

/* These must be macros.  Inlined functions are useless because the
   `__builtin_constant_p' predicate in dcgettext would always return
   false.  */

# undef gettext
# define gettext(msgid) dgettext (NULL, msgid)

# undef dgettext
# define dgettext(domainname, msgid)					      \
  dcgettext (domainname, msgid, LC_MESSAGES)

# if __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 7)
/* Variable defined in loadmsgcat.c which gets incremented every time a
   new catalog is loaded.  */
extern int _nl_msg_cat_cntr;

#  undef dcgettext
#  define dcgettext(domainname, msgid, category)			      \
  (__extension__							      \
   ({									      \
     char *__result;							      \
     if (__builtin_constant_p (msgid))					      \
       {								      \
	 static char *__translation__;					      \
	 static int __catalog_counter__;				      \
	 if (! __translation__ || __catalog_counter__ != _nl_msg_cat_cntr)    \
	   {								      \
	     __translation__ =						      \
	       dcgettext__ ((domainname), (msgid), (category));		      \
	     __catalog_counter__ = _nl_msg_cat_cntr;			      \
	   }								      \
	 __result = __translation__;					      \
       }								      \
     else								      \
       __result = dcgettext__ ((domainname), (msgid), (category));	      \
     __result;								      \
    }))
# endif
#endif /* Optimizing. */


__END_DECLS

#endif /* libintl.h */
