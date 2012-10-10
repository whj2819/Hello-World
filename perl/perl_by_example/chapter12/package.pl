#!/usr/bin/perl

require "ctime.pl";
require "pwd.pl";

&initpwd;
print "The present working directory is %s \n",$ENV{PWD},"\n";
&chdir("../..");
print "The present working directory is %s \n",$ENV{PWD},"\n";
$today = &ctime(time);
print "$today \n";
