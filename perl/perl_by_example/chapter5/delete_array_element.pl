#!/usr/bin/perl

@colors = qw (red green blue yellow);
print "@colors \n";

delete $colors[1];
print "@colors \n";
print "$colors[1] \n";

$size = @colors;
print "The size of the array is $size \n";

