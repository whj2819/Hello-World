#!/usr/bin/perl


my $hashref = {
    Name => "Woody",
    Type => "Cowboy"
};

print "$hashref->{Name} \n\n";
print keys %$hashref, "\n";
print values %$hashref, "\n";
