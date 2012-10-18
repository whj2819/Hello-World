#!/usr/bin/perl

use strict;
use warnings;
use Getopt::Long qw(GetOptionsFromArray);

my $mac = 0;
sub tcpdump_start {
    print "tcpdump start _____\n";
}

sub tcpdump_stop{
    print "tcpdump stop _____\n";
}
sub netcap{
    print "netcap \n";

    my %h = (
        'start'    => \&tcpdump_start,
        'stop'     => \&tcpdump_stop,
    );

    GetOptionsFromArray(
        \@_,
        \%h,
        'start',
        'stop',
        'mac=s'      => \$mac
    );
    print "\@_ @_ \n";
}

if (exists $ARGV[0]) {
    if (exists $main::{"${ARGV[0]}"}) {
        my $rv =$main::{"${ARGV[0]}"}(@ARGV[1 .. $#ARGV]);
    }
}


print "\@ARGV   @ARGV  \n";
