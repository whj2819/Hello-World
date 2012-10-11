#!/usr/bin/perl

use strict;
use warnings;

my $num = 5;
my $p = \$num;

print 'The address assigned $p is ',$p,"\n";
print "The value stored at that address is $$p \n";
