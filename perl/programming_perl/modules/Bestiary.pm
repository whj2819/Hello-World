package Bestiary 1.001;
require Exporter;

our @ISA = qw(Exporter);
our @EXPORT = qw(camel);
our @EXPORT_OK = qw(test $weight);

sub camel {
    print "One-hump dromedary \n";
}

sub test {
    print "tesst _______________ \n";
}

$weight = 1024;

1; # make require happy
