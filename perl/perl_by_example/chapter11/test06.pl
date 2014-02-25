#!/usr/bin/perl
use warnings;
use strict;

sub params {
    print "The values in the @_ array are @_ \n";
    print "The first value is $_[0] \n";
    print "The last value is ", pop @_, "\n";

    my $value ;

    foreach $value ( @_ ) {
        $value += 5;
        print "The value is $value \n";
    }
}

print "Give me 5 numbers: \n";
my @n = ();
@n = split(" ", <STDIN>);
&params(@n);
print "Back in main \n";
print "The new values are @n \n";
