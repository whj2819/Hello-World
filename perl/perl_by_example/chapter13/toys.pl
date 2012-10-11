#!/usr/bin/perl

@toys = qw(Barbie Elmo Thomas Barney);
$num = @toys;
%games = (
    "Nintendo"    => "Wii", 
    "Sony"        => "PlayStation 3",
    "Microsoft"   => "XBox 360",
);

$ref1 = \$num;
$ref2 = \@toys;
$ref3 = \%games;

print "There are $$ref1 toys.\n";
print "There are: ",join(",",@$ref2),".\n";
print "*" x 80,"\n\n";
print "Jessica's favorite toy is $ref2->[0].\n";
print "Willie's favorite toy is $ref2->[1].\n";

while (($key,$value) = each(%$ref3)) {
    print "$key    => $value \n";
}
print "The waited in line for a $ref3->{'Nintendo'} \n";
