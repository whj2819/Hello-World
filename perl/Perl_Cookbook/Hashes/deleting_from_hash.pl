#!/sur/bin/perl

use strict;
use warnings;

my %food_color = (
    Apple    => "red",
    Banana   => "yellow",
    Lemon    => "yellow",
    Carrot   => "orange"
);

sub print_foods {
    my @foods = keys %food_color;
    my $food ;

    print "keys:@foods \n";
    print "values: ";

    foreach $food (@foods) {
        my $color = $food_color{$food};

        if (defined $color) {
            print "$color ";
        } else {
            print "(undef)";
        }
    }
    print "\n";
}

print "Initially:\n";
print_foods();

print "\nWith Banand undef \n";
undef $food_color{"Banana"};
print_foods();

print "\nWith Banand undef \n";
delete $food_color{"Banana"};
print_foods();
