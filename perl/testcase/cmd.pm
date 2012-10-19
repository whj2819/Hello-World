
#
package cmd;

use warnings;
use strict;

use Exporter;
our @ISA = qw/Exporter/;
our @EXPORT=qw/
cmd_run
cmd_system
cmd_system_c
cmd_verbose
/;

my $verbose=0;
sub cmd_system{
	my $cmd = shift;
	my $ret;
	if($verbose){
		printf STDERR "cmd_system ==> $cmd\n" ;
	}
	$ret=system($cmd);
	if($verbose){
		printf STDERR "cmd_ret ==> $ret\n" ;
	}
}

#can capture stdout stderr
sub cmd_system_c{
	my $cmd = shift;
	my $ret;
	if($verbose){
		printf STDERR "cmd_system_c ==> $cmd\n" ;
	}

	my $err_msg='';
	my $out_msg='';

	{
		local(*STDERR);
	   	open(STDERR, ">", \$err_msg) or die "Can't open STDERR: $!";
		$out_msg = `$cmd`;
		$ret=$?;
	}

	if($verbose){
		printf STDERR "cmd_ret ==> $ret\n" ;
		printf STDERR "cmd_out_msg ==> $out_msg\n" ;
		printf STDERR "cmd_err_msg ==> $err_msg\n" ;
	}

	return ($ret,$out_msg,$err_msg);
}

sub cmd_verbose{
	$verbose = shift || 0;
}

sub help{
	my $cmd = shift;
	if($cmd eq '--list'){
		for my $k (sort keys %main::){
			if($k =~ 'do_.*'){
				$k =~ s/do_//;
				print "    $k\n";
			}
		}
	}elsif($cmd eq '--all'){
		for my $k (sort keys %main::){
			if($k =~ 'do_.*'){
				$k =~ s/do_//;
				print "    $k\n";
				print ${$main::{"do_$k"}};
			}
		}
	}elsif(exists $main::{"do_$cmd"}){
		print ${$main::{"do_$cmd"}};
	}else{
		print "unknown command\n";
	}
	return 0;
}

sub cmd_run{
	if(!@ARGV){
		push @ARGV,"help","--list";
	}

	my $arg0=shift @ARGV;
	my $func_name;

	if($arg0 eq 'help'){
		if(!@ARGV){
			help("--list");
		}
		else{
			help($ARGV[0]);
		}
		exit 0;
	}

	$func_name = "do_$arg0";
	if(exists $main::{$func_name}){
		my @args =  grep {
			if($_ eq '--verbose'){
				$verbose=1;
				0;
			}else{
				1;
			}
		} @ARGV;
		my $rv = $main::{$func_name}(@args);
		if($rv < 0){
			exit(-$rv);
		}
		exit 0;
	}

	print STDERR "[global]\n";
	print STDERR "error = unknown command\n";
	exit 1;
}

1;

