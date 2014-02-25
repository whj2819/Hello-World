#!/usr/bin/perl

$first = "Per";
$last = "Lindberg";

&greeting ($first, $last);
print "---$fname---\n" if defined $fname;

sub greeting {
    local ($fname, $lname) = @_;
    print "Welcome $fname \n";

}
