#!/usr/bin/perl

@town = qw(Boston Chico Tampa);
$friend = "Mary";
print "In main:\$friend is $friend \n";

package boy;
$name = "Steve";
print "In boy \$name is $name.\n";
$main::friend = "Patricia";
print "In boy \@town is @::town \n";

package main;
print "In main: \$name is $name.\n";
print "In main: \$name is $boy::name.\n";
print "In main: \$friend is $friend.\n";
