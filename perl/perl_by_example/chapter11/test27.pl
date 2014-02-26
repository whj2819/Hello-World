#!/usr/bin/perl

sub AUTOLOAD {
    print "$AUTOLOAD \n";
    my (@arguments) = @_;
    my ($package, $command) = split("::", $AUTOLOAD,2);
    return `$command @arguments`;
}


$day = date("+%D");
print "Today is $day.\n";
print cal(2, 2014);
