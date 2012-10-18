#!/usr/bin/perl

use Pod::Usage;
use strict;
use warnings;

my $message_text = "This text precedes the usage message.";
my $exit_status = 2;
my $verbose_level = 0;
my $filehandle = \*STDERR;

pod2usage($message_text);
pod2usage($exit_status);

pod2usage(
    {
        -message    => $message_text,
        -exitval    => $exit_status,
        -verbose    => $verbose_level,
        -output     => $filehandle
    }
);

pod2usage(
        -msg    => $message_text,
        -exitval    => $exit_status,
        -verbose    => $verbose_level,
        -output     => $filehandle
);

pod2usage(
        -verbose    => 2,
        -noperdoc   => 1 
);
