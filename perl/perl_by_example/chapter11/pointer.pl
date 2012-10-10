#!/usr/bin/perl

use warnings;

@toys = qw( Buzlightyear Woody Thomas Pokemon );
$num = @toys;
%movies = (
    "Toy Story" => "US",
    "Thomas" => "England",
    "Pokemon" => "Japan",
);

$ref1 = \$num;
$ref2 = \@toys;
$ref3 = \%movies;

print "There are $$ref1 toys.\n";
print "There are @$ref2 .\n";
while (($key,$value) = each(%$ref3)) {
    print "$key -- $value \n";
}

print "His favorite toys are $ref2->[0] and $ref2->[3] \n";
print "The Pokemon movie was made in $ref3->{'Pokemon'}. \n";

print "*" x 80,"\n\n\n";

$num = 5;
$p = \$num;
print 'The address assigned $p is ',$p,"\n";
print "The value stored at that address is $$p \n";


