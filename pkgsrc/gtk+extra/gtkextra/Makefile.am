## Makefile.am for gtk+extra

AUTOMAKE_OPTIONS = 1.4

gtkextra_public_h_sources = \
	gtkbordercombo.h \
	gtkcharsel.h \
        gtkcheckitem.h \
	gtkcolorcombo.h \
	gtkcombobox.h \
        gtkdirtree.h \
	gtkextra.h \
        gtkextrafeatures.h \
        gtkfilelist.h \
	gtkfileicons.h \
        gtkfontcombo.h \
        gtkiconfilesel.h \
        gtkiconlist.h \
	gtkitementry.h \
        gtkplot.h \
        gtkplot3d.h \
        gtkplotdt.h \
        gtkplotpolar.h \
        gtkplotdata.h \
        gtkplotpixmap.h \
        gtkplotbar.h \
        gtkplotbox.h \
        gtkplotflux.h \
        gtkplotsurface.h \
        gtkplotcsurface.h \
        gtkplotcanvas.h \
        gtkplotpc.h \
        gtkplotgdk.h \
        gtkplotps.h \
        gtkplotprint.h \
        gtkpsfont.h \
	gtksheet.h \
	gtktogglecombo.h 

gtkextra_c_sources = \
	gtkbordercombo.c \
        gtkcharsel.c \
        gtkcheckitem.c \
	gtkcolorcombo.c \
	gtkcombobox.c \
        gtkdirtree.c \
        gtkextra.c \
        gtkfilelist.c \
        gtkfontcombo.c \
        gtkiconlist.c \
	gtkitementry.c \
        gtkiconfilesel.c \
        gtkplot.c \
        gtkplot3d.c \
        gtkplotdt.c  \
        gtkplotpolar.c \
        gtkplotdata.c \
        gtkplotpixmap.c \
        gtkplotbar.c \
        gtkplotbox.c \
        gtkplotflux.c \
        gtkplotsurface.c \
        gtkplotcsurface.c \
        gtkplotcanvas.c \
        gtkplotpc.c \
        gtkplotgdk.c \
        gtkplotps.c \
        gtkplotprint.c \
        gtkpsfont.c \
	gtksheet.c \
	gtktogglecombo.c 

gtkextra_private_h_sources = \
	icons.h \
	pixmaps.h 

gtkextra_extra_sources = \
	gtkextrafeatures.h.in 

INCLUDES = $(GTK_CFLAGS) $(GTKGL_CFLAGS)

libgtkextraincludedir = $(includedir)/gtkextra
libgtkextrainclude_HEADERS = $(gtkextra_public_h_sources)

lib_LTLIBRARIES = libgtkextra.la
libgtkextra_la_SOURCES = $(gtkextra_c_sources)
libgtkextra_la_LDFLAGS = \
	-version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE) \
	-release $(LT_RELEASE) \
	-export-dynamic \
	$(shell gtk-config --libs) $(GTKGL_LIBS)
EXTRA_HEADERS +=
EXTRA_DIST += $(gtkextra_private_h_sources) gtkextra.def Makefile.win32 makefile.msc sat.xpm sg_small.xpm cloud.xpm suncloud.xpm testgtkplotdt.in

# test programs, not to be installed

noinst_PROGRAMS = testgtksheet testgtkiconlist testgtkfilesel testgtkplot testgtkfont testrealtime testiterator testpolar testgtkplot3d testcontour testbubbles testflux testboxes testimage testpixmap testcharsel testdt testgtkplotdt
DEPS = libgtkextra.la
LDADDS = libgtkextra.la $(GTK_LIBS)

testgtksheet_DEPENDENCIES = $(DEPS)
testgtkplot_DEPENDENCIES = $(DEPS)
testdt_DEPENDENCIES = $(DEPS)
testgtkplotdt_DEPENDENCIES = $(DEPS)
testpolar_DEPENDENCIES = $(DEPS)
testgtkplot3d_DEPENDENCIES = $(DEPS)
testcontour_DEPENDENCIES = $(DEPS)
testrealtime_DEPENDENCIES = $(DEPS)
testgtkfilesel_DEPENDENCIES = $(DEPS)
testgtkiconlist_DEPENDENCIES = $(DEPS)
testgtkfont_DEPENDENCIES = $(DEPS)
testbubbles_DEPENDENCIES = $(DEPS)
testflux_DEPENDENCIES = $(DEPS)
testboxes_DEPENDENCIES = $(DEPS)
testpixmap_DEPENDENCIES = $(DEPS)
testimage_DEPENDENCIES = $(DEPS)
testcharsel_DEPENDENCIES = $(DEPS)
testiterator_DEPENDENCIES = $(DEPS)
testgtksheet_LDADD = $(LDADDS)
testgtkplot_LDADD = $(LDADDS)
testdt_LDADD = $(LDADDS)
testgtkplotdt_LDADD = $(LDADDS)
testimage_LDADD = $(LDADDS)
testcharsel_LDADD = $(LDADDS)
testpixmap_LDADD = $(LDADDS)
testpolar_LDADD = $(LDADDS)
testgtkplot3d_LDADD = $(LDADDS)
testcontour_LDADD = $(LDADDS)
testrealtime_LDADD = $(LDADDS)
testgtkfilesel_LDADD = $(LDADDS)
testgtkiconlist_LDADD = $(LDADDS)
testgtkfont_LDADD = $(LDADDS)
testbubbles_LDADD = $(LDADDS)
testflux_LDADD = $(LDADDS)
testboxes_LDADD = $(LDADDS)
testiterator_LDADD = $(LDADDS)

files:
        @files=`ls $(DISTFILES) 2> /dev/null `; for p in $$files; do \
          echo $$p; \
        done

test: testgtksheet testgtkiconlist testgtkfilesel testgtkplot testgtkfont testrealtime testpolar testgtkplot3d testcontour testbubbles testflux testboxes testimage testpixmap testcharsel testdt testgtkplotdt testiterator
        builddir=`pwd`; cd $(top_builddir); top_builddir=`pwd`; export HAVE_PROGRESSBAR=1; \
        cd $$builddir; cd $(srcdir); \
        $(SHELL) $$top_builddir/libtool --mode=execute gdb $$builddir/testgtksheet;  \
        $(SHELL) $$top_builddir/libtool --mode=execute gdb $$builddir/testgtkplot;  \
        $(SHELL) $$top_builddir/libtool --mode=execute gdb $$builddir/testgtkpolar;  \
        $(SHELL) $$top_builddir/libtool --mode=execute gdb $$builddir/testgtkplot3d;  \
        $(SHELL) $$top_builddir/libtool --mode=execute gdb $$builddir/testgtkbubble;  \
        $(SHELL) $$top_builddir/libtool --mode=execute gdb $$builddir/testgtkflux;  \
        $(SHELL) $$top_builddir/libtool --mode=execute gdb $$builddir/testcontour;  \
        $(SHELL) $$top_builddir/libtool --mode=execute gdb $$builddir/testgtkiconlist;  \
        $(SHELL) $$top_builddir/libtool --mode=execute gdb $$builddir/testgtkfilesel;  \
        $(SHELL) $$top_builddir/libtool --mode=execute gdb $$builddir/testgtkfont;  \
        $(SHELL) $$top_builddir/libtool --mode=execute gdb $$builddir/testrealtime;  \
        $(SHELL) $$top_builddir/libtool --mode=execute gdb $$builddir/testiterator;  \
        $(SHELL) $$top_builddir/libtool --mode=execute gdb $$builddir/testimage;  \
        $(SHELL) $$top_builddir/libtool --mode=execute gdb $$builddir/testpixmap;  \
        $(SHELL) $$top_builddir/libtool --mode=execute gdb $$builddir/testcharsel; \
	$(SHELL) $$top_builddir/libtool --mode=execute gdb $$builddir/testdt \
		$$builddir/testgtkplotdt.in > $$builddir/testgtkplotdt.out; echo

