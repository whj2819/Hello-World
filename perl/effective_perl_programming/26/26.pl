#!/usr/bin/perl

use strict;
use warnings;
use List::Util qw(first max maxstr min minstr reduce shuffle sum );
use List::MoreUtils qw(pairwise);

my @a = (0 .. 20);
my @b = (10 .. 30);
my @c = ();


@c = pairwise {$a + $b} @a,@b;
print "\@a:@a \n";
print "\@b:@b \n";
print "\@c:@c \n";


__END__
my $max_number = max(0 .. 99);
my $max_str = maxstr( qw(Fido Spot Rower));
my $sum = sum(0 .. 100);
#my $sum = reduce{$a * $b} 1 .. 5;
my @list = (0 .. 50);
my $founded = first{$_ > 18} @list;

print "\$max_number:$max_number \n";
print "\$max_str:$max_str \n";
print "\$sum:$sum\n";
print "\$founded:$founded \n";

