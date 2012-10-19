#!/usr/bin/perl

use strict;
use warnings;
use Getopt::Long qw(GetOptionsFromArray);

my ($cmd,@args) = @ARGV;

sub stbmac_find {
    print "stbmac_find \n\n";
}

sub tcpdump_start {
    print "tcpdump start _____\n";
    print "\$cmd:$cmd,\@args:@args \n";
    print "\$mac-------------- $mac \n\n";
}

sub tcpdump_stop{
    print "tcpdump stop _____\n";
}

sub stbmac_find {
    print "stbmac_find \n\n";
}

sub do_netcap{
    print "netcap @args\n";

    my %h = (
        'start'    => \&tcpdump_start,
        'stop'     =>\&tcpdump_stop,
    );

    GetOptionsFromArray(
        \@_,
        \%h,
        'start',
        'mac=s',
        'stop',
    );
    print "start=>$h{start} \n";
    if (exists $h{mac}) {
        print "___________ mac=>$h{mac} \n";
    }
}

my $func_name = "do_$ARGV[0]";
if (exists $ARGV[0]) {
    if (exists $main::{$func_name}) {
        my $rv =$main::{$func_name}(@ARGV[1 .. $#ARGV]);
        if ($rv < 0) {
            exit (-$rv); 
        }
    }
    exit 0;
}

print STDERR "[global]\n";
print STDERR "error = unknown command \n";
exit 1;
