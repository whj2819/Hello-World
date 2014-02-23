#!/usr/bin/perl

use warnings;
use strict;

my @colors = qw(red green purple blue brown);
print "The original array is : @colors \n";

my @lostcolors= splice(@colors, 2, 3, "yellow", "orange");
print "The removed items are : @lostcolors\n";
print "The spliced array is now : @colors \n";
