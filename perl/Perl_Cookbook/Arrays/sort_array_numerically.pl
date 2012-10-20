#!/usr/bin/perl

use strict;
use warnings;

my @array = (1,5,8,9,2,3);


foreach my $line (sort {$b <=> $a} @array) {
    print "$line \n";
}

