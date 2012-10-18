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

=pon
    GetOptionsFromArray(
        \@_,
        'start',
        'stop',
        'mac=s'      => \$mac
    );
    #stbmac_find(\$mac);
    print "\@_ @_ \n";
=cut
GetOptions(
        'start'    => \&tcpdump_start,
        'stop'     =>\&tcpdump_stop,
        'mac=s'    => \$mac
    );
    #stbmac_find(\$mac);
    print "___________ $mac \n";
}

if (exists $ARGV[0]) {
    if (exists $main::{"${ARGV[0]}"}) {
        my $rv =$main::{"${ARGV[0]}"}(@ARGV[1 .. $#ARGV]);
    }
}


print "\@ARGV   @ARGV  \n";
