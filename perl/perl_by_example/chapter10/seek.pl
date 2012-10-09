#!/usr/bin/perl

use warnings;

open (FH, "db") or die "Can't open datebook:$!\n";

while (<FH>) {
    last if /Norma/;
}

seek (FH, 0, 1) or die;
$line = <FH>;
print "$line \n";

close FH;
