#!/usr/bin/perl

use warnings;
use strict;



my %weekday = (
    1 => 'Monday',
    2 => 'Tuesday',
    3 => 'Wednesday',
    4 => 'Thursday',
    5 => 'Friday',
    6 => 'Saturday',
    7 => 'Sunday'
);

foreach my $key (keys(%weekday)) {
    print "$key ";
}
print "\n";

foreach my $key (sort keys(%weekday)) {
    print "$key ";
}
print "\n";



my ($key,$value);
while( ($key, $value) = each(%weekday)) {
    print "$key = $value \n";
}
print "\n";





