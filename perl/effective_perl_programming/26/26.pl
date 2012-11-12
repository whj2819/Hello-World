#!/usr/bin/perl

use strict;
use warnings;
use List::Util qw(max maxstr);


my $max_number = max(0 .. 99);
my $max_str = maxstr( qw(Fido Spot Rower));

print "\$max_number:$max_number \n";
print "\$max_str:$max_str \n";





