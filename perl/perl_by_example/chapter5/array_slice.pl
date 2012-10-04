#!/usr/bin/perl

@names = ('Tom','Dic','Harry','Pete');
@pal = @names[1,2,3];
print "@pal \n\n";

($friend[0],$friend[1],$friend[2]) = @names;
print "@friend\n\n";
