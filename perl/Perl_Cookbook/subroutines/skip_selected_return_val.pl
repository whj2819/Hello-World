#!/usr/bin/perl

use strict;
use warnings;

my $filename = "wantarray.pl";
#my ($dev,$ino,$DUMMY,$uid) = stat($filename);
my $cnt;
$cnt = () = stat($filename);

print "cnt:$cnt\n";
__END__
print "dev:$dev \n";
print "ino:$ino \n";
print "dummy:$DUMMY\n";
print "uid:$uid \n";
