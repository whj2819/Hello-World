#!/usr/bin/perl

# closure
sub AUTOLOAD {
    my $name = our $AUTOLOAD;
    *$AUTOLOAD = sub {
        print "I see $name(@_) \n";
    };
    goto &$AUTOLOAD;
}

blarg(30);
blarg(40);
blarg(50);


__END__
sub AUTOLOAD {
    our $AUTOLOAD;

    return "I see $AUTOLOAD(@_) \n";
}

print blarg(10);
