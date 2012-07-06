#!/usr/bin/perl


$sum = 0;
$string = "an apple a day";
@test = unpack("C*",$string);
print "@test \n";
foreach $byteval (unpack("C*",$string)) {
    $sum += $byteval;
}
print "$sum \n";


$sum = unpack("%32C*",$string);
print "$sum ____\n";






=pon
%seen = ();
$string = "an apple a day";
@test = split (//,$string);
print "@test \n";

foreach $char (split //,$string) {
    print "$seen{$char} \n";
    $seen{$char}++;
}
@all_keys = keys %seen;
print "unique chars are:",@all_keys,"\n";

$string = "This is split test.";

@array = split(//,$string);
print "@array \n";
@array = unpack("U*",$string);
print "@array \n";
=cut

