#!/usr/bin/perl

use House;


my $house1 = House->new("Tom Savage", 25000);
my $house2 = House->new("Devin Quigley", 35000);



$house1->display_object;
$house2->display_object;
print "$house1, $house2 \n";
