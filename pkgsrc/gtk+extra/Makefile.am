## Makefile.am for gtk+extra

SRC_SUBDIRS = gtkextra docs
SUBDIRS = $(SRC_SUBDIRS)

bin_SCRIPTS = gtkextra-config

# require automake 1.4
AUTOMAKE_OPTIONS = 1.4

EXTRA_DIST = \
	TODO \
	gtk.m4 \
	gtkextra.m4 \
	acconfig.h \
        makecopyright \
	config.h.win32 \
        gtkextra.spec 

m4datadir = $(datadir)/aclocal
m4data_DATA = gtkextra.m4

files:
        @files=`ls $(DISTFILES) 2> /dev/null `; for p in $$files; do \
          echo $$p; \
        done
        @for subdir in $(SUBDIRS); do \
          files=`cd $$subdir; $(MAKE) files | grep -v "make\[[1-9]\]"`; \
          for file in $$files; do \
            echo $$subdir/$$file; \
          done; \
        done
release:
	rm -rf .deps */.deps
	$(MAKE) distcheck

snapshot:
	$(MAKE) dist distdir=$(PACKAGE)-`date +"%y%m%d"`

ChangeLog.cvs:
	cvs log | perl mkchlog > ChangeLog.cvs
