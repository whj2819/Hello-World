#!/usr/bin/perl

use File::Find;

find(\&wanted,'/home/wuhuajie','/home/wuhuajie/study');

sub wanted {
    -d $_ && print "$File::Find::name \n";
}
