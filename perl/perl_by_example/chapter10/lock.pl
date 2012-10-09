#!/usr/bin/perl

$LOCK_EX = 2;
$LOCK_UN = 8;

print "Adding an entry to the datafile.\n";
print "Enter the name: ";

chomp( $name = <STDIN>);
print "Enter the address: ";
chomp($address = <STDIN>);

open(DB, ">>datafile") || die "Can't open:$! \n";
flock(DB,$LOCK_EX);

print DB "$name:$address\n";

flock(DB,$LOCK_UN);
