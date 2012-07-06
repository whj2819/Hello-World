#!/usr/bin/perl

$string = "This is a test";
$revchars = reverse($string);
print "$revchars \n";

@test = reverse (split " ",$string);
print "@test \n";

$revwords = join(" ",reverse(split " ",$string));
print "$revwords \n";
