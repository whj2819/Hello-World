#!/usr/bin/perl

use strict;
use warnings;

my %wins = (
    "Portland Panthers" => 10,
    "Sunnyvale Sluggers" => 12,
    "Chico Wildcats" => 5,
    "Stevensville Tigers" => 6,
    "Lewiston Blazers" => 11,
    "Danville Terriors" => 8,
);

my $key;
foreach $key ( sort asc_sort_wins(keys %wins) ) {
    printf "\t%-20s%5d \n", $key, $wins{$key};
}

sub asc_sort_wins {
    $wins{$a} <=> $wins{$b};
}
