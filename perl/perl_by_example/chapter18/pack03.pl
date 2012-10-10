#!/usr/bin/perl

use warnings;

$str = "0x123456789ABCDE ellie...";
print "$str \n";

$bytes = unpack("H*",$str);
print "$bytes \n";

$str2 = pack("H*",$bytes);
print "$str2\n";

$bytes = unpack("h*",$str);
print "$bytes \n";

$str1 = pack("h*",$bytes);
print "$str1\n"; 
