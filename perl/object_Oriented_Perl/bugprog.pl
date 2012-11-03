#!/usr/bin/perl

use strict;
use warnings;
use Bug;


my $id = 1;
my $type = 2;
my $description = "This is a test";
#package main;
my $nextbug = Bug->new($id,$type,$description);


__END__
my $tmp = ref($nextbug); # return class name;
print "\$tmp:$tmp \n";
