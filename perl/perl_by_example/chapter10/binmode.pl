#!/usr/bin/perl

use warnings;

$infile = "statsbar.gif";

open (INFILE, "< $infile");
open (OUTFILE, "> outfile.gif");

binmode (INFILE);
binmode (OUTFILE);

whlie (read (INFILE, $buffer, 1024)) {
    print OUTFILE $buffer;
}

close (OUTFILE);
close (INFILE);

