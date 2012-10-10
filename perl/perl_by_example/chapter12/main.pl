#!/usr/bin/perl

use strict "vars";
use warnings;

our (@frineds ,@dog,$key,$value);
my ($name,$pal,$money);
$name = "Susanne";
@friends = qw (Joe Jeff Jan);
@dogs = qw (Guyson Lara Junior);

loacl $main::dude = "Ernie";
my $pal = "Linda";
my $money = 1000;
while (($key,$value) = each(%main::)) {
    print "$key:\t $value\n";
}
