#!/usr/bin/perl


my $petref = [
    {
        name => "Rover",
        type => "dog",
        owner => "Mr. Jones",
    },
    {
        name => "Sylvester",
        type => "cat",
        owner => "Mr. Black",
    },
];

print "The first pet's name is $petref->[0]{name} \n";
print "Printing an array of hashes. \n";



print "Adding a hash to the array. \n";

push @{$petref}, {
    owner => "Mrs. Crow",
    name => "Tweety",
    type => "bird"
};


for ($i = 0; $i < 3; $i++) {
    while( ($key, $value) = each ( %{$petref->[$i]} ) ) {
        print "key: $key\tvalue: $value \n";
    }

}
