#!/usr/bin/perl

$string = "fac\x{0237}ade";
print " 1_ $string \n";

$string = /fa.ade/;
print " 2_ $string \n";

$string = /fa\Xade/;
print " 3_ $string \n";

@chars = split(//,$string);
print "@chars \n";
@chars = $string =~ /(\X)/g;
print "@chars \n";



=pon
=cut
