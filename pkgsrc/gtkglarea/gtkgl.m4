# configure paths for GtkGLArea
#�Janne L�f 1999-17-2


# AM_PATH_GTKGL([ACTION-IF-FOUND [,ACTION-IF-NOT-FOUND]])
AC_DEFUN(AM_PATH_GTKGL,
[
AC_REQUIRE([AM_PATH_GTK])
AC_PROVIDE([AM_PATH_GTKGL])

AC_ARG_WITH(gl-prefix,    [  --with-gl-prefix=PFX   Prefix where OpenGL or Mesa is installed],
 gl_prefix="$withval",
 gl_prefix="")

AC_ARG_WITH(gtkgl-prefix, [  --with-gtkgl-prefix=PFX Prefix where GtkGLArea is installed],
 gtkgl_prefix="$withval",
 gtkgl_prefix="")


## tests for GTK

## tests for OpenGL
if test x$gl_prefix != x ; then
 GL_CFLAGS="-I$gl_prefix/include"
 GL_LDOPTS="-L$gl_prefix/lib"
else
 GL_CFLAGS=""
 GL_LDOPTS=""
fi

saved_LIBS="$LIBS"
saved_CFLAGS="$CFLAGS"

# test for plain OpenGL
AC_MSG_CHECKING([GL])
LIBS="$saved_LIBS $GTK_LIBS $GL_LDOPTS -lGLU -lGL"
AC_TRY_LINK( ,[ char glBegin(); glBegin(); ], have_GL=yes, have_GL=no)
AC_MSG_RESULT($have_GL)

if test x$have_GL = xyes; then

 GL_LIBS="-lGLU -lGL"

else

 # test for Mesa
 AC_MSG_CHECKING([Mesa])
 LIBS="$saved_LIBS $GTK_LIBS $GL_LDOPTS -lMesaGLU -lMesaGL"
 AC_TRY_LINK( ,[ char glBegin(); glBegin(); ], have_Mesa=yes, have_Mesa=no)
 AC_MSG_RESULT($have_Mesa)

 if test x$have_Mesa = xyes; then

  GL_LIBS="-lMesaGLU -lMesaGL"

 else

  # test for Mesa with threads
  AC_MSG_CHECKING([Mesa with pthreads])
  LIBS="$saved_LIBS $GTK_LIBS $GL_LDOPTS -lMesaGLU -lMesaGL -lpthread"
  AC_TRY_LINK( ,[ char glBegin(); glBegin(); ], have_Mesa_pthread=yes, have_Mesa_pthread=no)
  AC_MSG_RESULT($have_Mesa_pthread)

  if test x$have_Mesa_pthread = xyes; then
    
    GL_LIBS="-lMesaGLU -lMesaGL -lpthread"

  else

   #all failed
   LIBS="$saved_LIBS"
   CFLAGS="$saved_CFLAGS"
   GTKGL_LIBS=""
   GTKGL_CFLAGS=""
   ifelse([$2], , :, [$2])

  fi
 fi
fi

## tests for GtkGLArea

if test x$gtkgl_prefix != x; then
 GTKGL_CFLAGS="-I$gtkgl_prefix/include"
 GTKGL_LDOPTS="-L$gtkgl_prefix/lib"
else
 GTKGL_CFLAGS=""
 GTKGL_LDOPTS=""
fi

AC_MSG_CHECKING([GtkGLArea])
LIBS="$save_LIBS -lgtkgl $GTK_LIBS $GL_LDOPTS $GL_LIBS $GTKGL_LDOPTS"
AC_TRY_LINK( ,[ char gtk_gl_area_new(); gtk_gl_area_new(); ], have_gtkgl=yes, have_gtkgl=no)
AC_MSG_RESULT($have_gtkgl)

if test x$have_gtkgl = xyes; then

 LIBS="$saved_LIBS"
 CFLAGS="$saved_CFLAGS"
 GTKGL_CFLAGS="$GTKGL_CFLAGS $GL_CFLAGS"
 GTKGL_LIBS="$GTKGL_LDOPTS -lgtkgl $GL_LDOPTS $GL_LIBS"
 ifelse([$1], , :, [$1])

else

 LIBS="$saved_LIBS"
 CFLAGS="$saved_CFLAGS"
 GTKGL_LIBS=""
 GTKGL_CFLAGS=""
 ifelse([$2], , :, [$2])

fi

AC_SUBST(GTKGL_CFLAGS)
AC_SUBST(GTKGL_LIBS)

])
