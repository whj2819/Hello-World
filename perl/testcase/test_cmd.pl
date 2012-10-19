#!/usr/bin/perl

use strict;
use warnings;
use Getopt::Long qw(GetOptionsFromArray);

use cmd;


our $do_ls="do_ls usage ok\n";
sub do_ls{
	my %h = ('opt1' => 'apply');
	GetOptionsFromArray(\@_, \%h, 'opt1=s', 'opt2=s');
	print "opt1=>$h{opt1}\n";
	if(exists $h{opt2}){
		print "opt2=>$h{opt2}\n";
	}

	print "--------------\n";
	cmd_system("ls");
	print "--------------\n";
	cmd_system_c("ls");
	print "--------------\n";
}


cmd_run();





