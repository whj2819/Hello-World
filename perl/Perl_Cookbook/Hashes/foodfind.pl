#/usr/bin/perl

use strict;
use warnings;

my $given = shift @ARGV || die "usage:foodfind food or color.\n";
my %color = (
    Apple    => "red",
    Banana   => "yellow",
    Lemo     => "yellow",
    Carrot   => "orange"
);

my %food = reverse %color;

if (exists $color{$given}) {
    print "111 $given is a food with color $color{$given} \n";
}

if (exists $food{$given}) {
    print "222 $food{$given} is a food with color $given \n";
}



