#!/usr/bin/perl

use strict;
use warnings;
#use Getopt::Long qw(GetOptionsFromArray GetOptionsFromString);
use Getopt::Long qw(GetOptionsFromString);


my $ret;
my $string = "arg1 arg2 arg3"; 
my $string2 = "arg4 arg5 arg6"; 
my $args = 0;
my $args2 = 0;
sub help {
    print "Hello World \n";
}
($ret,$args) = GetOptionsFromString(
    $string,
    'help'   => \&help,
);

print "___ $string _+++__ @$args \n";

__END__
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
