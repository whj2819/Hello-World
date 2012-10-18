#!/usr/bin/perl

use strict;
use warnings;
use Getopt::Long;

my $width = 80;
sub process {
    print "Hello process @_ and \n";
}

# argument callback
GetOptions (
    'width=i'    =>\$width,
    '<>'         =>\&process
);
