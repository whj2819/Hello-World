#!/usr/bin/perl

use strict;
use warnings;

my %food_color = (
    Apple    => "red",
    Banana   => "yellow",
    Lemon    => "yellow",
    Carrot   => "orange"
);

my $key;
my $value;
my $food;
my $color;



foreach $key (keys %food_color) {
    print "$key \n";
}

print "\n" x 5;
while (($key,$value) = each %food_color) {
    print "$key -- $value \n";
}


foreach ("Banana","Martini"){
    if (exists($food_color{$_})) {
        print "$_ is food.\n";
    } else {
        print "$_ is a drink.\n";
    }
}

print "*" x 80,"\n";
print map{"$_ => $food_color{$_}\n"} keys %food_color;



print "*" x 80,"\n";
my %foods_with_color = ();
while (($food,$color) = each(%food_color)) {
    push(@{$foods_with_color{$color}},$food);
}

print "@{$foods_with_color{yellow}} were yellow foods.\n";


print "*" x 80,"\n";

# sort by their associted values;
foreach $food (sort {$food_color{$a} cmp $food_color{$b}} keys %food_color) {
    print "$food is $food_color{$food} \n";
}
