#!/usr/bin/perl

use strict;
use warnings;

my $recode = {
    NAME    => "Jashon",
    EMPNO   => 132,
    TITLE   => "deputy peon",
    AGE     => 23,
    SALARY  => 37_000,
    PALS    => ["Norbert","Rhys","Phineas"],
};

printf "I am %s,and my pals are %s.\n",
$recode->{NAME},
join(", ",@{$recode->{PALS}});
