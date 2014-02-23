#!/usr/bin/perl

@stores = (
    {
        "Boss"        => "Ari Goldberg",
        "Employees"   => 24,
        "Registers"   => 10,
        "Sales"       => 15000,00,
    },

    {
        "Boss"        => "Ben Chien",
        "Employees"   => 12,
        "Registers"   => 5,
        "Sales"       => 3500,00,
    },
);

print "The number of elements in the array:",$#stores + 1,"\n";

for ($i = 0;$i < $#stores + 1;$i++) {
    printf $stores[$i]->{"Boss"}."\n";
    printf $stores[$i]->{"Employees"}."\n";
    printf $stores[$i]->{"Registers"}."\n";
    printf $stores[$i]->{"Sales"}."\n";
    print "-" x 20,"\n";
}
