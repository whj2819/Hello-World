#!/usr/bin/perl

use strict;
use warnings;

my @strings = qw(Dog Just test Laaaa cat);
my @temp = ();

# 这个操作是逆序的,所以要倒着读上来!
my @sorted = map { $_->[1]}
             sort{$a->[0] <=> $b->[0]}
             map{[length $_,$_]}
             @strings;
print "\@sorted:@sorted\n";

__END__
@temp = map{[length $_,$_]} @strings;
@temp = sort{$a->[0] <=> $b->[0] }@temp;
my @sorted = map{ $_->[1]} @temp;
print "\@sorted:@sorted\n";
