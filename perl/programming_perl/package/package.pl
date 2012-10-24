#!/usr/bin/perl

#use strict;
#use warnings;

*PI = \3.14;
print $PI,"\n";

__END__
*units = populate();
print $units{kg},"\n";

sub populate {
    my %newhash = (
        km    => 10,
        kg    => 70
    );

    return \%newhash;
}





=pon
foreach my $symname  (sort keys %main::) {
    local *sym = $main::{$symname};

    print "\$$symname is defined\n" if defined $sym;
    print "\@$symname is nonnull \n" if @sym; 
    print "\%$symname is nonnull \n" if %sym; 
}
=cut
