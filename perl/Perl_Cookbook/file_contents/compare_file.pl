#!/usr/bin/perl


use strict;
use warnings;
use File::Compare;

my $file_1 = "a.c";
my $file_2 = "b.c";

if (compare($file_1,$file_2) == 0) {
    print "they're equal \n";
} else {
    print "they're not equal \n";
}

