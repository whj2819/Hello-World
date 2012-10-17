#!/usr/bin/perl

use Getopt::Long;

sub start{
    print "start+++++++++++ \n\n";
}

sub stop{
    print "stop_______ \n\n";
}

my $mac = '';
my ($cmd,@args) = @ARGV;

GetOptions(
    \%opts,
    'start' => sub{start()},
    'mac=s' => \$mac,
    'stop'      => sub{stop()}
);

print "****\@ARGV: @ARGV \n";
print "****\$cmd:$cmd   \@args:@args \n";
print "MAC: $mac \n";

