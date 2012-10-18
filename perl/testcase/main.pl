#!/usr/bin/perl

use strict;
use warnings;
use Getopt::Long qw(GetOptionsFromArray);

my $mac = 0;
my ($cmd,@args) = @ARGV;

sub tcpdump_start {
    print "tcpdump start _____\n";
}

sub tcpdump_stop{
    print "tcpdump stop _____\n";
}

sub stbmac_find {
    print "stbmac_find \n\n";
}

sub netcap{
    print "netcap @args\n";
=pon
    GetOptionsFromArray(
        \@_,
        'start',
        'stop',
        'mac=s'      => \$mac
    );
    stbmac_find(\$mac);
    print "\@_ @_ \n";
my %h = (
    'start'    => \&tcpdump_start,
    'stop'     =>\&tcpdump_stop
);
=cut

GetOptions(
    'start'    => \&tcpdump_start,
    'stop'     =>\&tcpdump_stop,
    'mac=s'    => \$mac
);
if ($args[0] eq '--start') {
    print "+++++++++++++++ \n";
    stbmac_find(\$mac);
}
print "___________ $mac \n";
}

if (exists $ARGV[0]) {
    if (exists $main::{"${ARGV[0]}"}) {
        my $rv =$main::{"${ARGV[0]}"}(@ARGV[1 .. $#ARGV]);
    }
}


print "\@ARGV   @ARGV  \n";
