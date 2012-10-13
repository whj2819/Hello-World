#!/usr/bin/perl

use Tie::IxHash;
use strict;
use warnings;


my %food_color = ();
my $food;
my $color;

tie %food_color,"Tie::IxHash";
$food_color{"Banana"} = "Yellow";
$food_color{"Apple"} = "Green";
$food_color{"Lemon"} = "Yellow";

print "In insertion order,the foods are: \n";
foreach $food (keys %food_color) {
    print "$food \n";
}


print "Still in insertion order,the food's colors are:\n";
while (( $food,$color) = each(%food_color)) {
    print "$food is colored $color. \n";
}
