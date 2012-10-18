#!/usr/bin/perl

use Pod::Usage;
use Getopt::Long;

use strict;
use warnings;

my $opt_help = 0;
my $opt_man = 0;

GetOptions (
    "help",
    "man",
    "flag1"
) || pod2usage(2);

pod2usage(1) if ($opt_help);
pod2usage(-verbose => 2) if ($opt_man);

print "\@ARGV:@ARGV \n";
pod2usage("$0: Too many files given.\n") if (@ARGV > 1);
