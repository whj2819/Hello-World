#!/usr/bin/perl

sub thefunc {
    my %args = (
        INCREMENT    => '10s',
        FINISH       => 5,
        START        => 0,
        @_,
    );

    print "INCREMENT:$args{INCREMENT} \n";
    print "FINSH:$args{FINSH} \n";
    print "START:$args{START} \n";
    print "\@_:@_ \n";
    if ($args{INCREMENT} =~ /(\d+s$)/) {
        print "-------\n";
        print "$1 \n";
    }
}

thefunc(START =>"+5m",INCREMENT => "15s");
