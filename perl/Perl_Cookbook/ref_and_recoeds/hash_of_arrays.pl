#!/usr/bin/perl

use strict;
use warnings;

my %HoA = (
    "a key"    => [3,4,5],
);


push @{ $HoA{"a key"} },12;

# Be warned that this:
my @values = @{ $HoA{number} };
print "222 @values\n";

# you must do this instead:
@values = exits ( $HoA{number}) 
                ?  @{ $HoA{number} }
                : ( );
