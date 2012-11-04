#!/usr/bin/perl

package CD::Music;


my $cd = CD::Music->new("Cano in D","Pachebel",
    "Boering Mubak GmbH","1729-678347-1",
    1,
    8,8,
    5.0
);

print $cd->name,"\n";
print "Room %s,shelf %s\n",$cd->location;

