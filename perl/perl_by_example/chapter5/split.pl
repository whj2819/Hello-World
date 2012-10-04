#!/usr/bin/perl

use warnings;

$string = "Joe Blow:11/12/86:10 Main St.:Boston,MA:02530";
@line = split(":",$string);
print @line,"\n";
print "The guy's name is $line[0].\n";
print "The birthday is $line[1].\n\n\n";


@str = split(":",$string,2);
print $str[0],"\n";
print $str[1],"\n";
print "\n" x 2;


@str = split(":",$string);
print $str[0],"\n";
print $str[1],"\n";
print $str[2],"\n";
print $str[3],"\n";
print $str[4],"\n";
print "\n" x 2;

( $name,$birth,$address) = split(":",$string);
print $name,"\n";
print $birth,"\n";
print $address,"\n";
print "\n" x 2;
