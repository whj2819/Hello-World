#!/usr/bin/perl


use Carp qw(croak);

print "Give me a grade: ";

$grade = <STDIN>;
try ($grade);

sub try {
    my ($number) = @_;
    croak "Illegal value:" if $number < 0 || $number > 100;
}
