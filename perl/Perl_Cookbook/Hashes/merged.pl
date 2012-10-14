#!/usr/bin/perl

use strict;
use warnings;

my %food_color = (
    Apple    => "red",
    Banana   => "yellow",
    Lemon    => "yellow",
    Carrot   => "orange"
);

my %drink_color = (
    Gallinao    => "yellow",
    "Mai Tai"   => "blue"
);
my $key,
my $value;

=pon
#first method
my %ingested_color = (%drink_color,%food_color);
while (($key,$value) = each %ingested_color) {
    print "$key => $value \n";
}
=cut

#second method

my %substance_color = ();
while (($key,$value) = each %food_color) {
    $substance_color{$key} = $value;

}

while (($key,$value) = each %drink_color) {
    $substance_color{$key} = $value;
}

while (($key,$value) = each %substance_color) {
    print "$key => $value \n";
}
