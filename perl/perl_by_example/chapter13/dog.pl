#!/usr/bin/perl

use strict;

$animal = "dog";
$dog = "Lady";

print "Your dog is called ${$animal} \n";
eval "\$$animal = 'Lassie';";
print "Why don't you call her ${$animal} ?\n";
