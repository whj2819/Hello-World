#!/usr/bin/perl



my @list1 = (1 .. 3);
my @list2 = (5, 10, 15, 20);

print "The total is: ", &addemup(\@list1, \@list2), "\n";

sub addemup {
    my ($arr1, $arr2) = (shift, shift);
    my $total= 0; # 中文版此处笔误
    print "$arr1 \n";# 中文版此处笔误
    print "$arr2 \n";

    foreach $num (@$arr1, @$arr2) {
        $total += $num;
    }
    $total;
}
