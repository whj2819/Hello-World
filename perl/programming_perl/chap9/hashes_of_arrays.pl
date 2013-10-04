#!/usr/bin/perl

use strict;
use warnings;

my %HoA = (
    flintstones    => ["fred","barney"],
    jetsons        => ["george","jane","elroy"],
    simpsons       => ["homer","marge","bart"],
);

my $family = 0;
=pon
foreach $family (keys %HoA) {
    print "$family:@{$HoA{$family}} \n";
}
=cut

foreach $family (keys %HoA) {
    print "$family:\n";
    for my $i (0 .. $#{$HoA{$family}}) {
        print "$i = $HoA{$family}[$i]\n";
    }
    print "\n";
}
=cut
