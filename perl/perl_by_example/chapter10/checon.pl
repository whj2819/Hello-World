#!/usr/bin/perl

use warnings;

unless ($#ARGV == 0) {
    die "Usage: $0 <argument>: $!";
}

open(PASSWD,"/etc/passwd") || die "Can't open $!";
$username = shift(@ARGV);
while ($pwline = <PASSWD>) {
    if($pwline =~ /$username:/) {
        last;
    }
}
close PASSWD;

open(LOGGEDON,"who |") || die "Can't open:$!";
while ($logged = <LOGGEDON>) {
    if ($logged =~ /$username/) {
        $logged_on = 1;
        last;
    }
}

close LOGGEDON;
die "$username is not logged on.\n" if ! $logged_on;

print "$username is logged on and running these processes.\n";
open(PROC,"ps -ef |") || die "Can't open:$! \n";

while ($line = <PROC>) {
    print "$line" if $line =~ /$username/;
}
close PROC;
print '*' x 80,"\n";
print "So long.\n";
