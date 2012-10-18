#!/usr/bin/perl

use strict;
use warnings;

my @a = (1,3,5,6,7,8);
my @b = (2,3,5,7,9);

my @union = ();
my @isect = ();
my @diff = ();

my %union = ();
my %isect = ();
my %count = ();

my $e;

=pon
# method
foreach $e (@a) {
    $union{$e} = 1
}

foreach $e (@b) {
    if ($union{$e}) {
        $isect{$e} = 1
    }

    $union{$e} = 1;
}
=cut

=pon
foreach $e (@a,@b) {
    $union{$e}++ && $isect{$e}++
}

@union = keys %union;
@isect= keys %isect;

print "\@union:@union \n";
print "\@isect:@isect\n";
=cut
