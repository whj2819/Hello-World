#!/usr/bin/perl

use strict;
use warnings;


my $scalar = 1;
my @array = (1, 2, 3);
my %hash = (
    zdd => 30,
    autumn => 27,
);

#method 1
print "$hash{zdd} \n";
my $sref = \$scalar;
my $aref = \@array;
my $href = \%hash;

#method 2
print "$$sref \n";
print "${$aref}[2] \n";
print "${$href}{zdd}\n";

my $key = keys %{$href};
print "$key \n";

#method 3
print "$aref->[0] \n";
print "$href->{zdd}\n";
