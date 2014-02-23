#!/usr/bin/perl




@colors = qw(red green blue yellow);

print "@colors \n";

delete $colors[1];
print "@colors \n";
print @colors ,"\n";

$size = @colors;
print "The size of array is: $size \n";
