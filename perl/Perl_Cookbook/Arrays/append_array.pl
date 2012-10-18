#!/usr/bin/perl

use strict;
use warnings;

my @members = qw(Time Files);
my @initiates = qw(An Arrow);

print "\@members:@members \n";
print "\@initiates:@initiates\n";

splice(@members,2,0,"like",@initiates);
print "\@members:@members \n";

splice(@members,0,1,"Fruit");
splice(@members,-2,2,"A","banana");

print "\@members:@members \n";
