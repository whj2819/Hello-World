#!/usr/bin/perl

use warnings;
use strict;

#my @list  = (tomatoes, tomorrow, potatoes, phantom, Tommy);
my @list  = qw(tomatoes tomorrow potatoes phantom Tommy);
my @items = grep( /tom/i, @list);
my $count = grep( /tom/i, @list);
#$count = grep{ /tom/i }@list;
#@items = grep{ /tom/i }@list;

print "Found items:@items\n";
print "Number of found $count \n";
