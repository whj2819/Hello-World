#!/usr/bin/perl

use strict "vars";
use warnings;

our (@friends, @dogs, $key, $value );
my ($name, $pal, $money);
$name = "Susanne";
@friends = qw(Joe Jeff Jan);
@dogs = qw(Guyson Lara Junior);

local $main::dude = "Ernie";
$pal = "Linda";
$money = 1000;

while ( ($key, $value) = each(%main::) ) {
    print "$key \t$value\n";
}
