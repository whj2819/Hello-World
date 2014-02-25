#!/usr/bin/perl

sub greeting;

my $first = "Charles";
my $last = "Dobbings";

greeting( $first, $last);

sub greeting {
    print "@_ \n";
    print "Welcome to the club, $_[0], $_[1] \n";

}

