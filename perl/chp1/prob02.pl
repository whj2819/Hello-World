#!/usr/bin/perl

=pon
$b = 0;
$c = 5;
$a = $b || $c;
print "$a \n";
=cut

$x = 0;
$x ||= "test";
print "__ $x \n";
