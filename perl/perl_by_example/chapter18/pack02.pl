#!/usr/bin/perl

$ints = pack("i3",5,-10,15);

open(BINARY,"+>binary") || die;
print BINARY "$ints";
seek(BINARY,0,0) || die;

while(<BINARY>) {
    ($n1,$n2,$n3) = unpack("i3",$_);
    print "$n1 $n2 $n3 \n";
}
