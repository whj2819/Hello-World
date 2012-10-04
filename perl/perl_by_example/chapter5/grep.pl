#!/usr/bin/perl

use warnings;

@list = qw(tomatoes tomorow potatoes phantom Tommy);
$count = grep( /tom/i,@list);
@items = grep( /tom/i,@list);
print "Found items:@items\nNumber found:$count \n";
