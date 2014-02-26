#!/usr/bin/perl

#require "ctime.pl";
require "pwd.pl";

&initpwd;
printf "The presetn working directory is %s \n", $ENV{PWD}, "\n";
&chdir("../..");

printf "The presetn working directory is %s \n", $ENV{PWD}, "\n";
