#!/usr/bin/perl

use strict;
use warnings;

my ($cmd,@args) = @ARGV; 
my $package_name = "$$.cap";
my $dump_all_of_pack = "tcpdump -i p2p1 -w /tmp/$package_name -c 10000 -s 1600 ";
my $dump_part_of_pack = $dump_all_of_pack;


if ($args[0] eq '--start') {
    my $rv;

   # if (! $args[1]) { # args --mac == NULL;
   #     usage();
   #     exit 1;
   # }

    $rv = tcpdump_start();
    if (! $rv) {
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
    my $rv= 0;
    my $stbmac = 0;

    if ($args[2]) { # IPTMAC is not null;
        $rv = stbmac_find(\$stbmac);
        print "\$stbmac:$stbmac \$rv:$rv \n";
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

if (! $args[1] eq '--mac') {
    usage();
    exit 1;
}
sub stbmac_find {
    my $index;
    my $iptmac = $args[2];
    my $stbmac = shift(@_);
    my @line= split("\n\n",`cat stb_info.txt`);
    my $match = 0;

    print "*" x 80,"\n";
    foreach (@line) {
        if ($_ =~ /ipt_id\=(([0-9a-fA-F]{2}:){5}[0-9a-fA-F]{2})/io) {
            next if $1 ne $iptmac;
            $match = 1;# iptmac exist;
            if ($_ =~ /stb_mac\=(([0-9a-fA-F]{2}:){5}[0-9a-fA-F]{2})/io) {
                $$stbmac = $1;
                return 0;
            }
             if (defined $$stbmac ) {
                    return -1;
             }
        } 
    }
    if (! $match) {
         print "This IPT MAC is not exist.\n";
         exit 1;
    }
}

sub tcpdump_stop{
    my @pid = ();
    my $value;

    get_tcpdump_pid(\@pid);
    foreach $value (@pid) {
        print "pid:$value \n";
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
        $tmp = join " ",unpack("A15x33A*",$line[$i]);
        push(@formatted_data,$tmp);
    }

    foreach(@formatted_data) {
        if ( $_ =~ /tcpdump\s+(\d+)\s+tcpdump/o) {
       #if ( $_ =~ /root\s+(\d+)\s+tcpdump/o) {
            push(@$pid,$1);
        }
    }
}

sub usage {
    print "*" x 80,"\n";
    print "control netcap --start  [ --mac  IPTMAC ] \n\n";
    print "*" x 80,"\n";
}

sub show_error {
    return 0;
}

sub show_info {
    return 0;
}
