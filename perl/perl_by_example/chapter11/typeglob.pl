#!/usr/bin/perl

use warnings;
#use strict;

sub printit 
{
    local(*whichone) = @_;
    print *whichone,"\n";
    $whichone = "Prism of Light";
    $whichone[0] = "PURPLE";
}

$colors = "rainbow";
@colors = qw(red green yellow);
&printit(*colors);

print "Out of subroutine.\n";
print "\$colors is $colors.\n";
print "\@colors is @colors.\n";
