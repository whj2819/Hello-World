#!/usr/bin/perl

print "Give me a number.";

chop($a = <STDIN>);
print "Give me a divisor.";
chop($b = <STDIN>);

eval {
    die unless $answer = $a/$b ;
};
warn $@ if $@;

printf "Division of %.2f by %.2f is %.2f. \n",$a,$b,
                    $answer if $anser;

print "I'm here now. Good-day! \n";

