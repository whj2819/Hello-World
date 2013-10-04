#!/usr/bin/perl

use strict;
use warnings;


my $scalar = 1;
my @array = (1, 2, 3);
my %hash = (
    zdd => 30,
    autumn => 27,
);

my $sref = \$scalar;
my $aref = \@array;
my $href = \%hash;
