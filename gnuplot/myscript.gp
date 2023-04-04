reset # force all graph-related options to default values
fname = "data.txt" # file name
set autoscale xfixmin # axis range automatically scaled to include the range
set autoscale xfixmax # of data to be plotted
set tics font ",18"
set xlabel "x" font ",18"
set ylabel "y" font ",18"
set lmargin at screen 0.1 # set size of left margin
set rmargin at screen 0.82 # set size of right margin
set bmargin at screen 0.12 # set size of bottom margin
set tmargin at screen 0.95 # set size of top margin
plot fname using 1:3 with lines
