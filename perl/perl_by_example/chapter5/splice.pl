#!/usr/bin/perl

use warnings;

@colors = qw (red green purple blue brown);
print "The original array is @colors \n";

@discarded = splice(@colors,2);
print "The elements removed after the splice are:@discarded.\n";
print "The spliceed array is now: @colors \n";


print "\n" x 3;

@colors = qw (red green purple blue brown);
print "The original array is @colors \n";

@lostcolors= splice(@colors,2,3,"yellow","orange");
print "The elements removed after the splice are:@lostcolors.\n";
print "The spliceed array is now: @colors \n";
