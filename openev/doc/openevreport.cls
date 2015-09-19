\NeedsTeXFormat{LaTeX2e}

\ProvidesClass{openevreport}[1998/01/13 OpenEV report class]

% Switch off some of the report options.
 
\DeclareOption{a4paper}{\OptionNotUsed}
\DeclareOption{a5paper}{\OptionNotUsed}
\DeclareOption{b5paper}{\OptionNotUsed}
\DeclareOption{letterpaper}{\OptionNotUsed}
\DeclareOption{legalpaper}{\OptionNotUsed}
\DeclareOption{executivepaper}{\OptionNotUsed}
\DeclareOption{landscape}{\OptionNotUsed}
\DeclareOption{twoside}{\OptionNotUsed}
\DeclareOption{titlepage}{\OptionNotUsed}
\DeclareOption{onecolumn}{\OptionNotUsed}

% The default action for any option is to pass it to the report class.
 
\DeclareOption*{\PassOptionsToClass{\CurrentOption}{report}}
 
% Execute the options.
 
\ProcessOptions
 
% Load the report class.
 
\LoadClass[oneside]{report}

% Load the graphics package (for including figures)

\RequirePackage{graphicx}

% Load the PostScript fonts package

\RequirePackage{pslatex}

% Load the fancy headings package

\RequirePackage{fancyhdr}

% Load the latex2html package

\RequirePackage{html}

% Define the heading fonts

\newcommand{\@headingfont}{\fontfamily{phv}\selectfont}

\newcommand{\@chapterfont}{%
   \@headingfont\bfseries\huge
}
\newcommand{\@sectionfont}{%
   \@headingfont\bfseries\Large
}
\newcommand{\@subsectionfont}{%
   \@headingfont\bfseries\slshape\large
}
\newcommand{\@subsubsectionfont}{%
   \@headingfont\bfseries\normalsize
}

% Redefine headings

\renewcommand\section{\@startsection {section}{1}{\z@}%
                                     {-3.5ex \@plus -1ex \@minus -.2ex}%
                                     {2.3ex \@plus.2ex}%
                                     {\@sectionfont}}
\renewcommand\subsection{\@startsection{subsection}{2}{\z@}%
                                     {-3.25ex\@plus -1ex \@minus -.2ex}%
                                     {1.5ex \@plus .2ex}%
                                     {\@subsectionfont}}
\renewcommand\subsubsection{\@startsection{subsubsection}{3}{\z@}%
                                     {-3.25ex\@plus -1ex \@minus -.2ex}%
                                     {1.5ex \@plus .2ex}%
                                     {\@subsubsectionfont}}

\renewcommand{\chapter}{%
   \if@openright\cleardoublepage\else\clearpage\fi
   \global\@topnum\z@
   \@afterindentfalse
   \secdef\@chapter\@schapter}

\def\@makechapterhead#1{%
  \vspace*{30\p@}%
  {\parindent \z@ \raggedright \normalfont
    \ifnum \c@secnumdepth >\m@ne
        \@chapterfont \@chapapp\space \thechapter.\hspace*{20\p@}%
    \fi
    \@chapterfont #1\par\nobreak
    \vskip 40\p@
  }}

% Page margins

\setlength{\textwidth}{6.0in}
\setlength{\oddsidemargin}{0.25in}
\setlength{\textheight}{8.0in}
\setlength{\topmargin}{0.0in}

\newcommand{\verticaloffset}[1]{\setlength{\voffset}{#1}}

% Headers and footers.

\pagestyle{fancy}

\lhead{\scshape OpenEV}
\chead{}
\rhead{\scshape\leftmark}

\lfoot{\slshape\today}
\cfoot{}
\rfoot{\thepage}

\renewcommand{\chaptermark}[1]{\markboth{#1}{}}

\renewcommand{\headrulewidth}{0.4pt}
\renewcommand{\footrulewidth}{0.4pt}

\newcommand{\headtext}[1]{\rhead{\scshape #1}}
\newcommand{\foottext}[1]{\lfoot{\slshape #1}}

% Set maximum number of figures/tables at top of page to 1

\setcounter{topnumber}{1}
\setcounter{totalnumber}{2}

% Other useful commands

% That's it!

\endinput
