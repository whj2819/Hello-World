#!/usr/bin/perl

use Carp qw(cluck);

print "Give me a grade: ";

$grade = <STDIN>;
try ($grade);

sub try {
    my ($number) = @_;

    cluck "Illegal value:" if $number < 0 || $number > 100;
}
print "That was just a warning.Program continues here. \n";

