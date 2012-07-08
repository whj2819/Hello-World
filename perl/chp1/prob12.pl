#!/usr/bin/perl

$var = 17;
$test = 'I am $var years old.';
print "____ $test \n";
$test =~ s/(\$\w+)/$1/gee;
print "____ $test \n";


=pon
our($rows,$cols);
no strict 'refs';
my $text;

($rows,$cols) = (24,80);
$text = q(I am $rows high and $cols long);
$text =~ s/\$(\w+)/${$1}/g;
print $text,"\n";
=cut



