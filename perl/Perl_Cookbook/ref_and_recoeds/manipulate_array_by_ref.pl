#!/usr/bin/perl

use strict;
use warnings;

my @array = (1,2,3,4,5,6,7,8);
my $aref = \@array;
my $ano_array= [1,2,3,4,5,6,7,8];
my $ano_copy= [@array];





=pon
print $aref->[5],"\n";
print $ano_array->[3],"\n";
print $ano_copy->[5],"\n";

push(@$ano_array,11);
print $ano_array->[8],"\n";

my $last_idx = $#{$aref};
print "\$last_idx:$last_idx \n";

my $num_items = @$aref;
print "\$num_items:$num_items\n";
=cut
