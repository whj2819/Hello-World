#!/usr/bin/perl

use warnings;

@list = qw(dog cat bird snake);
print "Original list: @list \n";

sub asc_sort {
    $a cmp $b;
}

@sorted_list = sort asc_sort(@list);
print "Ascii sort:@sorted_list \n";

sub numberic_sort {
    $a <=> $b;
}

@number_sort = sort numberic_sort 10,0,5,9.510,1000;
print "Number sort:@number_sort.\n";
