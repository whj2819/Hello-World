#!/usr/bin/perl

use strict;
use warnings;

my ($cmd,@args) = @ARGV; 
my $package_name = "$$.cap";
my $dump_all_of_pack = "tcpdump -i eth0 -w /tmp/$package_name -c 10000 -s 1600 ";
my $dump_part_of_pack = 0;

print "$cmd \n\n";
print "$package_name \n\n";

if ($args[0] eq '--start') {
    my $rv;

    if (! $args[1]) { # args --mac == NULL;
        usage();
        exit 1;
    }

    $rv = tcpdump_start();
    if ($rv) {
        show_error();
    } else {
        show_info();
    }
    exit 0;
} elsif ($args[0] eq '--stop') {
    tcpdump_stop();
    exit 0;
} else {
    usage();
    exit 1;
}

sub tcpdump_start {
    my $rv;
    my $stbmac;

    if (args[2]) { # IPTMAC is not null;
        rv = stbmac_find(\$stbmac);
        while (rv) { 
            rv = stbmac_find(\$stbmac);
            select(undef,undef,undef,0.5);# sleep 500ms 
        }
        $dump_part_of_pack .= " ether host ".$stbmac;
        $rv = system($dump_part_of_pack) ;
    } else {
        $rv =system($dump_all_of_pack);
    }

    return $rv;
}

if (! $args[1] eq '--mac') {
    usage();
    exit 1;
}
sub stbmac_find {
    my $index;
    my $iptmac = $args[2];
    my $stbmac = shift(@_);
    my @line= split("\n\n",`cat stb_info.txt`);
    my $ipdmac_match = 0;

    foreach (@line) {
        if ($_ =~ /ipt_id\=(([0-9a-fA-F]{2}:){5}[0-9a-fA-F]{2})/io) {
            next if $1 ne $iptmac;
            if ($_ =~ /stb_id\=(([0-9a-fA-F]{2}:){5}[0-9a-fA-F]{2})/io) {
                $$stbmac = $1;
                if ($$stbmac eq " ") {
                    return -1;
                }
                return 0;
            }
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

sub usage {
    print "control netcap --start  [ --mac  IPTMAC ] \n\n";
}

sub show_error {
    return 0;
}

sub show_info {
    return 0;
}
