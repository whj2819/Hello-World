#!/usr/bin/perl
use strict;
use warnings;


my @fruits = qw(Apple Blackberry);

my $ref = \@fruits;

foreach my $line (@{$ref}) {
    print "$line \n";
}
