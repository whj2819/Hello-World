#!/usr/bin/perl

@unicode_points = unpack("U*","fac\x{0327}ade");
print "@unicode_points \n"; 

$word = pack("U*",@unicode_points);
print "$word \n\n\n";
printf "%vd\n","fac\x{0327}ade";
printf "%vx\n","fac\x{0327}ade";


=pon
$hal = "HAL";
@byte = unpack("C*",$hal);
print "@byte \n";

foreach $val (@byte) {
    $val++;
} 

$ibm = pack("C*",@byte);
print "$ibm \n";


$char = 'A';
$num = ord($char);
print "$num ____ \n";
$num = 97;
$char = chr($num);
print "__ $char \n";

$string = "abcdefg";
@bytes = unpack("C*",$string);
print "@bytes \n";
$string = pack("C*",@bytes);
print "$string \n";

@ascii_character_numbers = unpack("C*","sample");
print "@ascii_character_numbers \n";
$word = pack("C*",@ascii_character_numbers);
print "$word \n";

=cut
