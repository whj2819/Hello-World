#!/usr/bin/perl

#use strict;
#use warnings;

=pon
#1.1.3 discussion
=cut
$string = "This is what you have";
#         +012345678901234567890  Indexing forwards  (left to right)
#          109876543210987654321- Indexing backwards (right to left)
#           note that 0 means 10 or 20, etc. above

$first  = substr($string, 0, 1);  # "T"
$start  = substr($string, 5, 2);  # "is"
$rest   = substr($string, 13);    # "you have"
$last   = substr($string, -1);    # "e"
$end    = substr($string, -4);    # "have"
$piece  = substr($string, -8, 3); # "you"
print "$first \n";
print "$start \n";
print "$rest \n";
print "$last \n";
print "$end \n";
print "$piece \n";












=pon
my $leading;
my $s1;
my $s2;
my $trailing;
my $data ="abcdefghijklmnopqrstuvwxyz";
my @fivers ;

($leading,$s1,$s2,$trailing) = unpack("A5 x3 A8 A8 A*",$data);
print "$leading $s1 $s2 $trailing \n";

@fivers= unpack("A5" x (length($data)/5),$data);
print "@fivers \n";

@fivers= unpack("A1" x (length($data)),$data);
print "@fivers \n";
#1.1.2 solution
my $string = "This is a test.";
my $newstring = "Newstring b";
my $offset = 4;
my $count = 4;
print "$string \n";

my $values ;
$values =  substr($string,$offset,$count);
print "11 $values \n";
$values =  substr($string,$offset);
print "22 $values \n";


substr($string,$offset,$count,$newstring);
print " $newstring \n";
print "$string \n";

my $newtail ="df";
substr($string,$offset) = $newtail;
print "$newtail \n";
print "$string \n";
=cut

