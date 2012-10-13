#!/usr/bin/perl

use strict;
use warnings;


my %surname = (
    "Mickey"    => "Mantle",
    "Babe"      => "Ruth"
);

my %first_name = reverse %surname;
print $first_name{"Mantle"},"\n";
