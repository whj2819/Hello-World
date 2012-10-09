#!/usr/bin/perl

use warnings;

$infile = "statsbar.gif";

open (INFILE, "<$infile");
open (OUTFILE, ">outfile.gif");

binmode(INFILE);
binmode(OUTFILE);

while (read(INFILE, $buffer, 1024)) {
    print OUTFILE $buffer;
}

close (INFILE);
close (OUTFILE);

