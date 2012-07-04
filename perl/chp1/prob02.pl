#!/usr/bin/perl


$dir = shift(@ARGV) || "/tmp";
print @ARGV ;
print "\n$dir \n";

=pon
$foo = $bar || "Default value.";
print "$foo \n";
$b = 0;
$c = 5;
$a = $b || $c;
print "$a \n";

$x = 1;
$x ||= "test";
print "__ $x \n";
=cut
