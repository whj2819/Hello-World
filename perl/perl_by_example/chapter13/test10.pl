#!/usr/bin/perl

my $hashref = {
    Math => {
        Anna => 100,
        Hao => 95,
        Rita => 85,
    },

    Science => {
        Sam => 78,
        Lou => 100,
        Vijay => 98,
    },
};

print "Anno got $hashref->{Math}{Anna} on the Math test .\n";
$hashref->{Science}{Lou} = 90;
print "Lou's grade was changed
to $hashref->{Science}{Lou} \n";

#print %{$hashref->{Math}}, "\n";

foreach $key (keys %{$hashref}) {
    print "$key \n";
    while ( ($k, $v) = each( %{$hashref->{$key}}) ) {
        print "--$k--$v \n";
    }
}





