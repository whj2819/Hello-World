#!/usr/bin/perl

package House;

my $ref = {
    Owner => "Tom",
    Price => "25000",
};

bless ($ref, House);

print "The value of \$ref is: $ref. \n";
print "The ref function return the class (package) name: ",
    ref($ref), "\n";

