#!/usr/bin/perl

use strict;
use warnings;
use Getopt::Long qw(GetOptionsFromArray GetOptionsFromString);

my $ret;
my $value = '';
my @array = qw(arg1 arg2 arg3 arg5);
my @tmp= qw(arg9 arg1 arg3 arg5);
my $verbose  = '';
my $debug= 0;

$ret = GetOptions(
    'verbose=i'    => \$verbose,
    'debug'
);

my %h = (
    'verbose'    => \$verbose,
    'debug'      => \$debug
);

=pon
$ret = GetOptionsFromArray(
    \@array,
    'verbose=i' =>  \$verbose,
) || die "xxxxxxx \n";
=cut
print "\@array:@array\n\n";
print "\@array:@tmp\n\n";
print "\$verbose:$verbose\n\n";
print "\$debug:$debug\n\n";
print "$ret +========== \n\n";

__END__
if (exists $h{'verbose'}) {
    print "__exists_----- \n";
} else {
    print "_+not exists+++++++++++-- \n";
}

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
