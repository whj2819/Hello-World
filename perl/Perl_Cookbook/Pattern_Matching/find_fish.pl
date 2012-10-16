#!/usr/bin/perl

use strict;
use warnings;

my $count = 0;
$_ = 'One fish two fish red fish blue fish';
my @tmp = ($_ =~ /(\w+)\s+fish\b/gi); 
print "@tmp \n\n";

my @evens = grep { ++$count %2 == 0 } @tmp;
#my @evens = grep { $count++ %2 == 0 } /(\w+)\s+fish\b/gi;

print "Even numbered fish are @evens. \n";








=pon
my $pond = 'One fish two fish red fish blue fish';

my $WAIT = 3;
my $count = 0;

while ( $pond =~ /(\w+)\s+fish\b/gi) {
    if ( ++$count == $WAIT ) {
        print "The third fish is a $1 one .\n";
    }
}
=cut
