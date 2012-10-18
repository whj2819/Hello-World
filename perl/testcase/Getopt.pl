#!/usr/bin/perl

use strict;
use warnings;
use Getopt::Long qw(GetOptionsFromArray GetOptionsFromString);

my $ret;
my $ref;
my $value = '';
my @array = qw(arg1 arg2 arg3,arg5);
my $verbose  = 0;
my $debug= 0;

my %h = (
    'verbose'    => \$verbose,
    'debug'      => \$debug
);
$ret = GetOptionsFromArray(
    \@array,
    \%h,
    'verbose',
    'value!'   => \$value
);

print "\@array:@array\n\n";
print "\$value:$value\n\n";
print "\$verbose:$verbose\n\n";
print "\$debug:$debug\n\n";

if ($verbose) {
    print "___----- \n";
} else {
    print "_++++++++++++-- \n";
}

__END__
my $ret;
my $string = "arg1 arg2 arg3"; 
my $args = 0;
my $args2 = 0;
sub help {
    print "Hello World \n";
}
($ret,$args) = GetOptionsFromString(
    $string,
    'help'   => \&help
);

print "___ $string _+++__ @$args \n";

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
