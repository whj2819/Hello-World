#!/usr/bin/perl

use strict;
use warnings;

my %citrus_color = (
    Lemon    => "yellow",
    Orange  => "orange",
    Lime    => "green"
);

my %food_color = (
    Apple    => "red",
    Banana   => "yellow",
    Lemon    => "yellow",
    Carrot   => "orange"
);

# build up a list of no-citrus foods;

my @non_citrus = ();

foreach (keys %food_color) {
    #push (@non_citrus,$_)   unless $citrus_color{$_};
    push (@non_citrus,$_)   if $citrus_color{$_};

}

print "@non_citrus \n\n\n";
