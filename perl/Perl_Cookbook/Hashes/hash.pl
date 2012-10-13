#!/usr/bin/perl

use strict;
use warnings;

my %food_color = (
    Apple    => "red",
    Banana   => "yellow",
    Lemon    => "yellow",
    Carrot   => "orange"
);

my $key;
my $value;


while (($key,$value) = each %food_color) {
    print "$key -- $value \n";
}


foreach ("Banana","Martini"){
    if (exists($food_color{$_})) {
        print "$_ is food.\n";
    } else {
        print "$_ is a drink.\n";
    }
}

print "*" x 80,"\n";
print map{"$_ => $food_color{$_}\n"} keys %food_color;
