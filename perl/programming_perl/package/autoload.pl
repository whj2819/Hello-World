#!/usr/bin/perl

sub AUTOLOAD {
    our $AUTOLOAD;
    warn "Attempt to call $AUTOLOAD failed .\n";
}

blarg(10);
print "Still alive! \n";
