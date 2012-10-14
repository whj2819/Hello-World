#!/usr/bin/perl

use strict;
use warnings;

my %father = (
    Cain    => 'Adam',
    Abel    => 'Adam',
    Seth    => 'Adam',
    Enoch   => 'Cain',
    Irad    => 'Enoch',
    Mehujael=> 'Irad',
    Methusael=> 'Mehujael',
    Lamech  => 'Methusael',
    Jabal   => 'Lamech',
    Jubal   => 'Lamech',
    Tubalcain=> 'Lamech',
    Enos    => 'Seth'
);

while (<>) {
    chomp;
    do {
        print "$_ ";
        $_ = $father{$_};
    }while defined;
    print "\n";
}
