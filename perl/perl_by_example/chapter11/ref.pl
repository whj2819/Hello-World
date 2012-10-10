#!/usr/bin/perl

#use warnings;

@list = (1,2,3,4,5);
$list = "grocery";

*arr = \@list;
print @arr,"\n";
print "$arr \n";

sub alias {
    local (*a) = @_;
    $a[0] = 7;
    pop @a;
}

&alias(*arr);
print "@list \n";
$num = 5;
*scalar = \$num;
print "$scalar \n";
