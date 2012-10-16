#!/usr/bin/perl

use strict;
use warnings;

my @people = ();
sub what_about_that_array {
    print "The array now has ", scalar(@people), " elements. \n";
    print "Element #3 is `$people[3]'. \n";
}

@people = qw(Crosby Stills Nash Young);

what_about_that_array(); 
