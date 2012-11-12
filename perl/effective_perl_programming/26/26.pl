#!/usr/bin/perl

use strict;
use warnings;
use List::Util qw(first max maxstr min minstr reduce shuffle sum);


my $max_number = max(0 .. 99);
my $max_str = maxstr( qw(Fido Spot Rower));
my $sum = sum(0 .. 100);
#my $sum = reduce{$a * $b} 1 .. 5;

print "\$max_number:$max_number \n";
print "\$max_str:$max_str \n";
print "\$sum:$sum\n";


