#!/usr/bin/perl

use File::Spec;

$pathname = File::Spec->catfile("C:", "Perl", "lib", "CGI");
print "$pathname \n";
