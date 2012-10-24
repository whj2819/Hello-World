#!/usr/bin/perl

use strict;
use warnings;

my $c1 = mkcounter(20);
my $c2 = mkcounter(77);

printf "next c1: %d \n",$c1->{NEXT}->();
printf "next c2: %d \n",$c2->{NEXT}->();
printf "next c1: %d \n",$c1->{NEXT}->();
printf "last c1: %d \n",$c1->{PREV}->();
printf "old c2: %d \n",$c2->{RESET}->();

sub mkcounter {
    my $count = shift ;
    my $start = $count;

    my $bundle = {
        NEXT    => sub { return ++$count},
        PREV    => sub { return --$count},
        GET     => sub { return $count},
        SET     => sub { return $count = shift},
        BUMP    => sub { return $count += shift},
        RESET   => sub { return $count = $start},
    };
    $bundle->{LAST} = $bundle->{PREV};
    return $bundle;
}
