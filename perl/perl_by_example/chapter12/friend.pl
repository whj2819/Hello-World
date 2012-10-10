#!/usr/bin/perl

$name = "Suzanne";
$num = 100;

package friend;
sub welcome {
    print "Who is your pal?";
    chomp($name = <STDIN>);
    print "Welcome $name! \n";
    print "\$num is $num.\n";
    print "Where is $main::name? \n\n";
}

package main;
&friend::welcome;
print "Back in main package \$name is $name \n";
print "Switch to friend package,Bye",$friend::name,"\n";
print "Bye $name \n\n";

package birthday;
$name = "Beatrice";
print "Happy Birthday,$name.\n";
print "No,$::name and $friend::name,it is not in you birthday.\n";

