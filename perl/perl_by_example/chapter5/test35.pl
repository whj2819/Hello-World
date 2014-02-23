#!/usr/bin/perl


use warnings;
use strict;

my $name = "Joe Blow";
my $birth = "11/12/86";
my $address = "10 Main St. ";

print join(":", $name, $birth, $address), "\n";
