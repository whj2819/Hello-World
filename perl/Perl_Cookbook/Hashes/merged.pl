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
my %substance_color = ();

=pon
#first method
my %ingested_color = (%drink_color,%food_color);
while (($key,$value) = each %ingested_color) {
    print "$key => $value \n";
}
=cut

=pon
#second method
while (($key,$value) = each %food_color) {
    $substance_color{$key} = $value;

}

while (($key,$value) = each %drink_color) {
    $substance_color{$key} = $value;
}

=cut

# third method 
my $substanceref;
foreach $substanceref (\%food_color, \%drink_color) {
    while (($key,$value) = each %$substanceref) {
        $substance_color{$key} = $value;
    }
}


while (($key,$value) = each %substance_color) {
    print "$key => $value \n";
}
