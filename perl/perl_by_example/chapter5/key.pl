#!/usr/bin/perl

use warnings;

%weekday = (
    '1'    => 'Monday',
    '2'    => 'Tuesday',
    '3'    => 'Wednesday',
    '4'    => 'Thursday',
    '5'    => 'Friday',
    '6'    => 'Saturday',
    '7'    => 'Sunday',
);

foreach $key (keys(%weekday)) {
    print "$key ";
}

print "\n";

foreach $key (sort keys(%weekday)) {
    print "$key ";
}

print "\n";

foreach $value (values(%weekday)) {
    print "$value ";
}

print "\n";

while (($key,$value) = each(%weekday)) {
    print "$key = $value \n";
}
