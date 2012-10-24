#!/usr/bin/perl

use strict;
use warnings;

my %hash = (
    key    => "test",
    key2    => "test2",
);

my $href = \%hash;

print "$href->{key} \n";

my $anon_hash = {
    key1    => "value1",
    key2    => "value2",
};

print "$anon_hash->{key2} \n";

my $anon_copy = { %hash };
print "$anon_copy->{key2} \n";


my @keys = sort keys %$anon_hash;
print "\@keys:@keys \n";

my $value = $href->{key2};
print "\$value:$value \n";

my @values = @$href{"key","key2"};
print "\@values:@values \n";
