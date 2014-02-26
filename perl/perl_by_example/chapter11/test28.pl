#!/usr/bin/perl

chdir "/stuff" || die "Can't cd :$! \n";
BEGIN {
    print "Welcome to my Program 01. \n"
};

END {
    print "Bailing out somewhere near line", __LINE__,
                                            " So long. \n"
};
