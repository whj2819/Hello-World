pacakge Bestiary;
require Exporter;

our @ISA = qw(Exporter);
our @EXPORT = qw(camel);
our @EXPORT_OK = qw($weight);
our $version = 1.00;

sub camel {
    print "One-hump dromedary"
}

$weght = 1024;

1; # make require happy
