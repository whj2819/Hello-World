#!/usr/bin/perl

use Cat;
use Dog;

my $dogref = Dog->new;
my $catref = Cat->new;

$dogref->set_attributes("Rover", "Mr. Jones", "Mutt");
$catref->set_attributes;

$dogref->get_attributes;
print "\n\n";
$catref->get_attributes;

