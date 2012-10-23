#!/usr/bin/perl

use strict;
use warnings;


my %HoH = (
    flintstones => {
        husband     => "fred",
        pal         => "barney",
    },
    jetsons => {
        husband    => "george",
        wife       => "jane",
        "his boy"  => "elroy",
    },
    simpsons   => {
        husbond    => "homer",
        wife       => "marge",
        kid        => "bart",
    },
);

$HoH{mash} = {
    captain    => "pierce",
    major       => "burns",
    corporal   => "radar",
};

for my $family (keys %HoH) {
    print "$family:\n";
    for my $role (keys $HoH{$family}) {
        print "$role = $HoH{$family}{$role}";
    }
    print "\n\n";
}
