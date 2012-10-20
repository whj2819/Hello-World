#!/usr/bin/perl

use strict;
use warnings;


sub shift2(\@) {
    return splice(@{$_[0]},0,2);
}

my @friends = qw (Peter Paul Mary Jim Tim);

my ($this,$that) = ();

($this,$that) = shift2(@friends);
print "\$this:$this,\$that:$that \n";
print "\@friends:@friends \n";

test

__END__
my @array = (1,2,3,4,5,6,7,8);
my @tmp = ();

print "@array\n";

@tmp = splice(@array,-5);
print "@tmp\n";

