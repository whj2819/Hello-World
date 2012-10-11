package Me;

use strict;
use warnings;

#require 5.6;
require Exporter;

our @ISA = qw(Exporter);
our @EXPORT_OK = qw(hello goodbye);

sub hello {
    my ($name) = shift;
    print "Hi there, $name. \n";
}
sub goodbye {
    my ($name) = shift;
    print "Good-bye, $name. \n";
}

sub do_nothing {
    print "Didn't print anything.
    Not in EXPORT list \n";
}

