#!/use/bin/perl

use strict;
use warnings;

my %ucnt = ();

for (`who`) {
    s/\s.*\n//;
    $ucnt{$_}++;
}

my @users = sort keys %ucnt;
print "users logged in:@users \n";
