#!/usr/bin/perl


open(MYPIPE, "| wc -w");
print MYPIPE "apples pears peaches";

close MYPIPE;
