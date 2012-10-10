#!/usr/bin/perl

unshift(@INC,"/home/whj2819/");
require "average.pl";

print "Enter you midterm scores.\n";
@scores = split(' ',<STDIN>);
print "The average is ",average::ave(@scores),"\n";
