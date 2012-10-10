#!/usr/bin/perl

use warnings;

if ($#ARGV < 1){
    die "Usage: $0 pattern filename(s) \n";
}

$pattern = shift;
while ($line = <ARGV>) {
    print "$ARGV: $.:$line" if $line =~ /$pattern/i;
    close(ARGV) if eof;
}
