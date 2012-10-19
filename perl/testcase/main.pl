#!/usr/bin/perl

use strict;
use warnings;
use Getopt::Long qw(GetOptionsFromArray);

my ($cmd,@args) = @ARGV;
my $package_name = "$$.cap";
my $dump_all_of_pack = "tcpdump -i eth0 -w /tmp/$package_name -c 10000 -s 1600 ";
my $dump_part_of_pack = $dump_all_of_pack;

sub get_tcpdump_pid {
    my $pid = shift(@_);
    my @line =split("\n", `ps -ef | grep tcpdump | grep -v grep`);
    my $index = $#line + 1;
    my $i;
    my $tmp;
    my @formatted_data = ();

    for ($i = 0;$i < $index;$i++) {
        $tmp = join " ",unpack("A13x33A*",$line[$i]);
        push(@formatted_data,$tmp);
    }

    foreach(@formatted_data) {
        if ( $_ =~ /root\s+(\d+)\s+tcpdump/o) {
            push(@$pid,$1);
        }
    }
}

sub tcpdump_stop{
    my @pid = ();
    my $value;

    get_tcpdump_pid(\@pid);
    foreach $value (@pid) {
        system("kill $value");
    }
}

sub stbmac_find {
    my $index;
    my $iptmac = $args[2];
    my $stbmac = shift(@_);
    my @line= split("\n\n",`~/ipgdctl stb.list`);

    print "*" x 80,"\n";
    foreach (@line) {
        if ($_ =~ /ipt_id\=(([0-9a-fA-F]{2}:){5}[0-9a-fA-F]{2})/io) {
            next if $1 ne $iptmac;
            if ($_ =~ /stb_mac\=(([0-9a-fA-F]{2}:){5}[0-9a-fA-F]{2})/io) {
                $$stbmac = $1;
                return 0;
            }
            if (defined $$stbmac ) {
                return -1; # stbmac is null;
            }
        }
    }
    print "This IPT MAC is not exist.\n";
    exit 1;
}

sub tcpdump_start {
    my $rv= 0;
    my $stbmac = 0;
    my $iptmac = $args[2];

    print "tcpdump start _____\n";
    print "\$cmd:$cmd,\@args:@args \n";
    if ($iptmac) { # IPTMAC is not null;
        $rv = stbmac_find(\$stbmac);
        print "______\$stbmac:$stbmac \$rv:$rv \n";
        while ($rv) {
            $rv = stbmac_find(\$stbmac);
            select(undef,undef,undef,0.5);# sleep 500ms
        }

        $dump_part_of_pack .= " ether host ".$stbmac;
        $rv = system($dump_part_of_pack) ;
    } else {
        $rv =system($dump_all_of_pack);
    }

    return $rv;
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
        'stop',
        'mac=s',
    ) || usage();
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

sub usage {

}

print STDERR "[global]\n";
print STDERR "error = unknown command \n";
exit 1;


