#!/use/bin/perl

#use strict;
#use warnings;


=pon
($package,$filename,$line,$subr,$has_args,$wantarray,
    $evaltext,$is_require,$hints,$bitmask
) = caller($i);

print "\$package:$package\n";
print "\$filename:$filename\n";
print "\$line: $line\n";
print "\$subr: $subr\n";
print "\$has_args: $has_args\n";
print "\$wantaray: $wantarray\n";
print "\$evaltext: $evaltext\n";
print "\$is_require: $is_require\n";
print "\$hints: $hints\n";
print "\$bitmask: $bitmask\n";
=cut
my $me = whoami();
my $him = whowasi();

sub whoami {
    (caller(2))[3]
}

sub whowasi {
    (caller(2))[3]
}

sub test {
    tmp();
}

sub tmp {
    my $test = whoami();
    print "\$test:$test\n";
}

test();
