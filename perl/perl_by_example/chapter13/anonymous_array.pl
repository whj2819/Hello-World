#!/usr/bin/perl

my $arrayref = ['Woody', 'Buzz', 'Bo', 'Mr.Potato Head'];

print "The value of the reference,\$arrayref is",$arrayref ,"\n";
print "$arrayref->[3] \n";
print "$$arrayref[3] \n";
print "${$arrayref}[3] \n";
print "@{$arrayref} \n";
print "*" x 80,"\n";
