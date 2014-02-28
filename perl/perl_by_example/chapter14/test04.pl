#!/usr/bin/perl

use House;
my $house = House->new();


print "\$houseref in main belongs to class ", 
    ref($house), "\n";


$house->set_owner("Tom Savage");
$house->display_owner;
