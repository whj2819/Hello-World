#!/usr/bin/perl

@list = (1,"test",0,"foo",20);
@has_digit = grep{/\d/} @list;
print "@has_digit \n";
