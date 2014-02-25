#!/usr/bin/perl -i.bak

while (<ARGV>) {
    tr/a-z/A-Z/;
    print;
    close ARGV if eof;
}
