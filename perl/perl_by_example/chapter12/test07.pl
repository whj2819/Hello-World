#!/usr/bin/perl





unshift (@INC, "/home/whj2819/projects/Hello-World/perl/perl_by_example/chapter12");
require "average.pl";

print "Enter your midterm scores. \n";
@scores = split(' ', <STDIN>);
printf "Teh average is %.1f \n", average::ave(@scores);
