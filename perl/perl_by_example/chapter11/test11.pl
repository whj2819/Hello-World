#!/usr/bin/perl


$colors= "rainbow";
@colors = qw(red green yellow );

&printit(*colors);

sub printit {
    local (*whichone) = @_;
    print *whichone, " \n";
    $whichone = "Prism of Light";
    $whichone[0] = "PURPLE";
}

print "Out of subroutine. \n";
print "\$colors is $colors. \n";
print "\@colors is @colors. \n";
