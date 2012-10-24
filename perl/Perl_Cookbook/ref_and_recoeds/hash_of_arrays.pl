#!/usr/bin/perl

use strict;
use warnings;

my %HoA = (
    "a key"    => [3,4,5],
);

my @values = @{ $HoA{"a key"} };
print "@values\n";
