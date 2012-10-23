#!/usr/bin/perl

use strict;
use warnings;

my @AoH = (
    {
        husband    => "barney",
        wife       => "betty",
        son        => "bamm bamm",
    },
    {
        husband    => "george",
        wife       => "jane",
        son        => "elroy",
    },
    {
        husband    => "homer",
        wife       => "marge",
        son        => "bart",
    },
);

push @AoH,{
        husband    => "fred",
        wife       => "wilma",
        daughter   => "pebbles",
};

for my $i (0 .. $#AoH) {
    print "$i is { ";
    for my $role (keys %{$AoH[$i]}) {
        print "$role = $AoH[$i]{$role}";
    }
    print " }\n";
}
=pon
for my $href (@AoH) {
    print "{ ";
    for my $role (keys %$href) {
        print "$role = $href->{$role} ";
    }
    print " } \n";
}
=cut

__END__
arrays of hashes
