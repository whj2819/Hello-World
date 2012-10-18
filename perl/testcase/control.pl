#!/usr/bin/perl

use strict;
use warnings;

my ($cmd,@args) = @ARGV;
my $package_name = "$$.cap";
my $dump_all_of_pack = "tcpdump -i eth0 -w /tmp/$package_name -c 10000 -s 1600 ";
my $dump_part_of_pack = $dump_all_of_pack;

if ($cmd eq "netcap") {
    netcap();
    exit 0;
} elsif ($cmd eq "reboot_system") {
    reboot_software_system();
    exit 0;
} elsif ($cmd eq "reboot_switch_module") {
    reboot_switch_module();
    exit 0;
} elsif ($cmd eq "reboot_eoc_module") {
    reboot_eoc_module();
    exit 0;
} elsif ($cmd eq "reboot_eoc_moderm") {
    reboot_eoc_moderm();
    exit 0;
} elsif ($cmd eq "reboot_rf") {
    reboot_rf();
    exit 0;
} elsif ($cmd eq "reboot_ipt") {
    reboot_ipt();
    exit 0;
} elsif ($cmd eq "factory_config") {
    factory_config();
    exit 0;
} else {
    usage();
    exit 1;
}

sub netcap {
    if ($args[0] eq '--start') {
        my $rv;

        $rv = tcpdump_start();
        if (! $rv) {
            show_info();
        }
    } elsif ($args[0] eq '--stop') {
        tcpdump_stop();
    } else {
        usage();
        exit 1;
    }
}

sub tcpdump_start {
    my $rv= 0;
    my $stbmac = 0;

    if ($args[2]) { # IPTMAC is not null;
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

if (! $args[1] eq '--mac') {
    usage();
    exit 1;
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

sub reboot_software_system {
    print "\treboot_system.......\n\n";
    my $reason = shift(@_);

    if ( $args[0] ne "--reason") {
        usage();
        exit 1;
    }

    write_reason_to_file(\$reason);
}

sub write_reason_to_file {
    my $reason = shift(@_);
    my $log = `date`;

    chomp($log);
    $log .= ":" . $$reason . "\n";
    open (REASON,">>/tmp/reason.txt") || die "Can't open file:$!\n";
    print REASON $log;

    close REASON;
}

sub reboot_switch_module {

}

sub reboot_eoc_module {

}

sub reboot_eoc_moderm {

}

sub reboot_rf {

}

sub reboot_ipt {

}

sub factory_config{

}

sub usage {
    print "*" x 80,"\n";
    print "\tcontrol netcap --start [ --mac IPTMAC ] \n";
    print "\tcontrol netcap --stop \n";
    print "\tcontrol reboot_system --reason strings\n";
    print "\t\te.g: control  reboot_system  --reason  upgrade/eocsearch/coredump/ \n";
    print "\tcontrol reboot_switch_module\n";
    print "\tcontrol reboot_eoc_module\n";
    print "\tcontrol reboot_eoc_moderm\n";
    print "\tcontrol reboot_rf\n";
    print "\tcontrol reboot_ipt\n";
    print "\tcontrol factory_config\n";
    print "*" x 80,"\n";
}

sub show_error {
    return 0;
}

sub show_info {
    print "\t\ntcpdump ok \n\n";
    return 0;
}

