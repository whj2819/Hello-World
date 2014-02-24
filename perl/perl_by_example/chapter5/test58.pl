#!/usr/bin/perl

use warnings;
use strict;

sub desc_sort_subject {
    $b <=> $a;
}

sub asc_sort_subject {
    $a <=> $b;
}

my %course = (
    101 => "Intro to Computer Science",
    221 => "Linguistics",
    300 => "Astronomy",
    102 => "Perl",
    103 => "Php",
    200 => "Language arts",
);


my $key;
print "\n\t Course in Ascending Numeric Order: \n";
foreach $key (sort asc_sort_subject(keys %course)) {
    printf "\t%-5d%s\n", $key, $course{"$key"};
}

print "\n\t Course in Desceding Numeric Order: \n";
foreach my $key (sort desc_sort_subject(keys %course)) {
    printf "\t%-5d%s\n", $key, $course{"$key"};
}

