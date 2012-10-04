#!/usr/bin/perl

use warnings;

$name = "Joe Blow";
$birth = "11/12/86";
$address = "10 Main St.";

print join(":",$name,$birth,$address),"\n";

@names = qw(Dan Dee Scotty Liz Tom);
@names = join("\n",sort(@names));
print @names,"\n";

