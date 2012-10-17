#!/usr/bin/perl

use Getopt::Long;

my $verbose = '';
my $all = '';
my $tag = ''; 
my $libfiles= ''; 


GetOptions (
    'verbose+'   => \$verbose,# option variable with default value (false)
    'all'        => \$all,
    'tag=s'      => \$tag,
    'librarys=s@' =>\$libfiles
);

#@libfiles = split(/,/,join(',',@libfiles));
print "\$verbose:$verbose \n";
print "\$all:$all\n";
print "\$tag:$tag\n";
print "\@libfiles:$libfiles->[0]\n";
