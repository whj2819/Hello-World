#!/usr/bin/perl



my %grades = (
    Math => [90, 100, 94],
    Science => [77,87,86],
    English => [65, 76, 99]
);

print "%grades \n";
print "The third math grade is:$grades{Math}->[2]. \n";
print "All of the Science grades are: @{$grades{Science}}. \n";
