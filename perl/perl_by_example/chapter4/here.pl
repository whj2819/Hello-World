#!/usr/bin/perl

$price = 1000;
print <<EOF;
The consumer commented,"As I look over my budget,I'd say
the price of $price is right.I'll give you \$500 to start."\n
EOF


#
# perl 版本问题
# 将print << x 4; 改成
# print <<"" x 4;
#
print <<"" x 4;
Here's to a new day.
Cheers!

print "\nLet's executs some commands. \n";
#
# 这里是反引号
#
print <<`END`;
echo Today is
date
END
