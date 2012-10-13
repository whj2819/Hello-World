#!/usr/bin/perl

use strict;
use warnings;

my %foo_color = (
    Apple    => "red",
    Banana   => "yellow",
    Lemon    => "yellow",
    Carrot   => "orange"
);

my $key;
my $value;


while (($key,$value) = each %foo_color) {
    print "$key -- $value \n";
}


foreach ("Banana","Martini"){
    if (exists($foo_color{$_})) {
        print "$_ is food.\n";
    } else {
        print "$_ is a drink.\n";
    }
}
