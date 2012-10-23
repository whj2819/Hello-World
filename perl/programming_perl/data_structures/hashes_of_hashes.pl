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

my $family;
my $roles;
my $role;
my $person;

while (($family,$roles) = each %HoH) {
    print "$family";
    while (($role,$person) = each %$roles) {
        print "$role = $person ";
    }
    print "\n\n";
}


__END__
for my $family (keys %HoH) {
    print "$family:\n";
    for my $role (keys $HoH{$family}) {
        print "$role = $HoH{$family}{$role}";
    }
    print "\n\n";
}
