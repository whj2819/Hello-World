#!/usr/bin/perl

use strict;
use warnings;


my $value = 10;
my $scalar_ref = \$value;

my $anon_scalar_ref; 
undef $anon_scalar_ref;
${$anon_scalar_ref} = 5;

my $constant_scalar_ref = \18;

print "\$scalar_ref:${$scalar_ref} \n";
print "\$anon_scalar_ref:${$anon_scalar_ref} \n";
print "\$constant_scalar_ref:${$constant_scalar_ref} \n";

__END__
# warnnigs
$constant_scalar_ref = 28;
print "\$constant_scalar_ref:${$constant_scalar_ref} \n";
