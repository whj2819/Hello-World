#!/usr/bin/perl

use strict;
use warnings;

my @AoA = (
    ["fred","barney"],
    ["george","jane","elroy"],
    ["homer","marge","bart"],
);

print "$AoA[2][1] \n";

my $ref_to_AoA = [ 
    ["fred","barney","pebbles","bamm bamm","dino",],
    ["homer","bart","marge","maggie",],
    ["george","jane","elroy","judy",],
];

print $ref_to_AoA->[2][3],"\n";
print $ref_to_AoA->[2]->[3],"\n";

