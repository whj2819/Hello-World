#!/bin/perl   


@names = qw(Tom Raul Steve Jon);


print "Hello $names[1] \n", if exists $names[1];
print "Out of range! \n", if not exists $names[5];
