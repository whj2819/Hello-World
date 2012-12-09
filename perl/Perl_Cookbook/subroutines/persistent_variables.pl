#!/usr/bin/perl

{
    my $counter;

    sub next_counter{
        return $counter++;
    }

}

$cnt = next_counter();
print "\$cnt:$cnt\n";
$cnt = next_counter();
print "\$cnt:$cnt\n";
$cnt = next_counter();
print "\$cnt:$cnt\n";


print "$counter \n";
