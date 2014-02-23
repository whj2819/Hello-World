#!/usr/bin/perl


%students = (
    "Math" => { "Joe" => 100, "Joan" => 95},
    "Science" => {"Bill" => 85, "Dan" => 76}
);

print "On the math test Joan got ";
print "$students{Math}->{Joan}. \n";

print "On the Science test Bill got ";
print "$students{Science}->{Bill}. \n";
