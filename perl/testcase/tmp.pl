#!/usr/bin/perl

use strict;
use warnings;

my $compile_cmd_74 = 'make clean && make distclean && make menuconfig && make';
my $compile_cmd_500 = 'make clean && make distclean && make menuconfig && make';
my $args = $ARGV[0];
my $result ;
my $args_num = @ARGV;



print "[$args_num] \n";

if ( $args_num != 1) {
    &usage();
    exit;
}

if ($args == 74) {
#    system($compiled_cmd_74);
    print "74 \n";
    $result = system('ls -l ');
    print "_______[$result] \n";

} elsif ($args == 500) {
#    system($compiled_cmd_500);
    print "500 \n";
    $result = system('ls -al ');
} else {
    &usage();
}

if ($result == 0) {
    //&copy_file_to_dst();
}

sub usage {
    printf "*" x 80 . "\n";
    print " useage: XXX.PL 74 or XXX.PL 500 \n";
    printf "*" x 80 . "\n";
}

