#!/usr/bin/perl

use Getopt::Long;

my $verbose = '';
my $all = '';
my $tag = ''; 
my $libfiles= ''; 
my @coor = () ; 
my %defines = ();


GetOptions (
    'verbose+'   => \$verbose,# option variable with default value (false)
    'all'        => \$all,
    'tag=s'      => \$tag,
    'librarys=s@' =>\$libfiles,
    'coordinates=f{2}' =>\@coor,
    'defines=s'   => \%defines
);

=pon
while (( $key,$value) = each %defines) {
    print"$key => $value \n";
}
=cut
