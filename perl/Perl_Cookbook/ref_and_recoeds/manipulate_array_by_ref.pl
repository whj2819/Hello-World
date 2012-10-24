#!/usr/bin/perl

use strict;
use warnings;

my @array = (1,2,3,4,5,6,7,8);
my $aref = \@array;
my $ano_array= [1,2,3,4,5,6,7,8];
my $ano_copy= [@array];

print $aref->[5],"\n";
print $ano_array->[3],"\n";
print $ano_copy->[5],"\n";
