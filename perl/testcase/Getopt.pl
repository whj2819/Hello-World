#!/usr/bin/perl

use strict;
use warnings;
use Getopt::Long;

my $width = 80;
my $value = 10;
my $mac = 0;

my ($cmd,@args) = @ARGV;
sub tcpdump_start{
    print "\@args :@args \n";
    print "Hello process @_ \n";
}

if ($cmd eq "netcap") {
# argument callback
    GetOptions (
        'start'         =>\&tcpdump_start,
        'stop'          =>\&tcpdump_stop,
        'mac=s'         =>\$mac,
    );
}
