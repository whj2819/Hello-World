#!/usr/bin/perl

use warnings;

$bytes = pack("c5",80,101,114,108,012);
print "$bytes\n";

$string = pack("A15A3","hey","you");
print "$string \n";

open(PW, "/etc/passwd") || die "Can't open file:$!";
open(CODEPW, ">codepw") || die "Can't open file:$!";

while (<PW>) {
    $uuline = pack("u*",$_);
    print CODEPW $uuline;
}

close PW;
close CODEPW;

print "\n=================华丽的分割线========================\n";
open(UUPW,"codepw") || die "Can't open file:$!\n";
while (<UUPW>) {
    print;
}

close UUPW;
print "\n\n";
print "\n=================华丽的分割线========================\n";

open(DECODED,"codepw")|| die "Can't open file:$!\n";
while (<DECODED>) {
    @decodeline = unpack("u*",$_);
    print "@decodeline";
}
