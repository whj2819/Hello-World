#!/usr/bin/perl

use strict;
use warnings;

my ($a,$b) = (3,8);
my @array_of_scalar_ref = \($a,$b);

print "\@array_of_scalar_ref:${$array_of_scalar_ref[0]}\n";

${$array_of_scalar_ref[1]} = 18;
print "\@array_of_scalar_ref:${$array_of_scalar_ref[1]}\n";
