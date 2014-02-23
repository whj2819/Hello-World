#!/usr/bin/perl

use warnings;
use strict;

my @list = (0x53, 0x77, 0x65, 0x64, 0x65, 0x6e, 0xa);
my @words = map chr, @list;


print @words;

my @n = (2, 4, 6, 8);

@n = map $_ * 2 + 6, @n;
print "@n \n";
