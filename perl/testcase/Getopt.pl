#!/usr/bin/perl

use Getopt::Long;

my $verbose = '';
my $all = '';

GetOptions (
    'verbose!'   => \$verbose,# option variable with default value (false)
    'all'       => \$all
);

print "\$verbose:$verbose \n";
print "\$all:$all\n";
