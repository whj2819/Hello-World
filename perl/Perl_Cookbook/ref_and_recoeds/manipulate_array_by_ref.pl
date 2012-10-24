#!/usr/bin/perl

use strict;
use warnings;

my @array = (1,2,3,4,5,6,7,8);
my $aref = \@array;

print $aref->[5],"\n";
