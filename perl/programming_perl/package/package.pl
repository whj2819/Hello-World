#!/usr/bin/perl

use strict;
use warnings;

sub identify_typeglob {
    my $glob = shift;

    print 'You gave me ',*{$glob}{PACKAGE}, '::',*{$glob}{NAME},"\n";
}

identify_typeglob(*foo);
identify_typeglob(*bar::glarch);






__END__

*PI = \3.14;
print $PI,"\n";
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
