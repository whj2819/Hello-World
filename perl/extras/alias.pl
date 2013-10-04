#!/usr/bin/perl

use strict;
use warnings;
use Switch;

my $args = @ARGV;
switch($args) {
    case 0  {
        system('git config --get-regexp "alias.*" | colrm 1 6 | sed "s/[ ]/ = /" | sort');
    }
    case 1 {
        system("git alias | grep -e $ARGV[0]");

    }
    else {
        system("git config --global alias.$ARGV[0] $ARGV[1]");
    }
}


__END__
用perl 重写git extras
