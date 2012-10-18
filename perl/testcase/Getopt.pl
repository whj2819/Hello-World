#!/usr/bin/perl


use strict;
use warnings;

use Getopt::Long;
use Pod::Usage;

my $verbose = 0;
my $debug = 0;
my %h = (
    'verbose'    => \$verbose,
    'debug'      => \$debug
);


GetOptions (
    \%h,
    'verbose',
    'debug',
    'filter',
    'size=i'
);

if ($verbose) {
    print "\$verbose:$verbose \n";
}

if (exists $h{filter}) {
    print "option 'filter'  was specified....\n";
}
