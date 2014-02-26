#!/usr/bin/perl

#use warnings;

sub AUTOLOAD {
    print "@_ \n";
    my (@arguments) = @_;
    $args = join(', ',@arguments);
    print "$AUTOLOAD was never defined.\n";
    print "The arguments passed were $args.\n";
}

$driver = "Jody";
$miles = 50;
$gallons = 5;
 
&mileage($driver,$miles,$gallons);
