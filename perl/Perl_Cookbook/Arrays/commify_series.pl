#!/usr/bin/perl

use strict;
use warnings;

my @lists = (
    ['just one thing'],
    [qw(Mutt Jeff)],
    [qw(Peter Paul Mary)],
);

my $aref = 0;

foreach $aref (@lists) {
    print "The list is: " . commify_series(@$aref) . ".\n";
}
print "\n\n";
print "*" x 80,"\n";

my @list = qw(one two three);
print "The list is: " . commify_series(@list) . ".\n";

sub commify_series {
    my $sepchar = grep(/,/ =>@_) ? ";" : ",";
    (@_ == 0) ? ''                                :
    (@_ == 1) ? $_[0]                             :
    (@_ == 2) ? join(" and ",@_)                  :
                join("$sepchar ",@_[0 ..($#_-1)],"and $_[-1]");

}
