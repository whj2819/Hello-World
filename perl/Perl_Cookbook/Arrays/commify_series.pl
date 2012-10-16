#!/usr/bin/perl

use strict;
use warnings;

my @lists = (
    ['just one thing'],
    [qw(Mutt Jeff)],
    [qw(Peter Paul Mary)],
    ['To our partents','Mother Theresa','God'],
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
    # => 在这里用作分隔符 
    my $sepchar = grep(/,/ => @_) ? ";" : ",";
    (@_ == 0) ? ''                                :
    (@_ == 1) ? $_[0]                             :
    (@_ == 2) ? join(" and ",@_)                  : # 如果只有2个数据
                join("$sepchar ",@_[0 ..($#_-1)],"and $_[-1]"); # 列表中大于2个数据

}
