DOC = openev
FUTURE = future
L2H_OPT = -show_section_numbers -no_navigation
L2H_INC = l2h-init.perl
SPLIT = 0
L2H_FLAGS = $(L2H_OPT) -split $(SPLIT) -init_file $(L2H_INC)

FIGS = openev_bigpicture.eps gvclass.eps gvdata.eps lodgen.eps phaseclip.eps

default: all

%.eps : %.fig
	fig2dev -L ps $< $@

$(FUTURE).dvi : $(FUTURE).tex
	latex $*
#	-@grep 'Rerun to get cross-references right' $*.log && latex $*

$(DOC).dvi : $(DOC).tex $(FIGS)
	latex $*
	-@grep 'Rerun to get cross-references right' $*.log && latex $*

$(DOC)/%.html : %.tex $(FIGS) $(L2H_INC)
	latex2html $(L2H_FLAGS) $*

all: $(DOC).dvi $(FUTURE).dvi

print: $(DOC).dvi
	dvips $*

html: $(DOC)/$(DOC).html

html-force: $(FIGS)
	latex2html $(L2H_FLAGS)

html-clean:
	rm -rf $(DOC)

clean:
	rm -f $(DOC).aux $(DOC).dvi $(DOC).log $(DOC).toc $(FIGS)
	rm -f $(FUTURE).aux $(FUTURE).dvi $(FUTURE).log
	rm -rf $(DOC) $(FUTURE)
