#!/usr/bin/perl


use warnings;
use strict;



my @colors = qw(red green purple blue brown);
print "The original array is @colors \n";

my @discarded = splice(@colors, 2, 2);
print "The elements removed after the splice are: @discarded \n";
print "The spliced array is now @colors \n";
