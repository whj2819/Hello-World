#!/usr/bin/perl -w

use strict;

my $dir = "/usr/local/bin";

print "Text files in $dir are:\n";
opendir(BIN,$dir) or die "Can't open $dir:$!";

while (my $file = readdir BIN) {
    next if $file =~ /^\.\.?$/; # skip . and ..
    print "$file \n" if -B "$dir/$file";
}
closedir(BIN);
