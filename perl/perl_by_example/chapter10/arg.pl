#!/usr/bin/perl

use warnings;

die "$0 requires an argument.\n" if $#ARGV < 0;

print "@ARGV \n";
print "\$ARGV[0] $ARGV[0]\n";
print "\$ARGV[1] $ARGV[1]\n";
print "There are ", $#ARGV + 1," arguments \n";

print "$ARGV[$#ARGV] is the last one.\n";
print "program name :$0 \n";
