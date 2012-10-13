#/usr/bin/per.

use strict;
use warnings;


my %ttys = ();
open (WHO,"who |");

my $user;
my $tty;
while (<WHO>) {
    ($user,$tty) = split;
    push ( @{$ttys{$user}},$tty );
}

foreach $user(sort keys %ttys) {
    print "$user:@{$ttys{$user}} \n";
}
