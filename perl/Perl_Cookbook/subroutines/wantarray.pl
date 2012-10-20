#!/usr/bin/perl


sub mysub {
    if (wantarray()) {
        print "In list context\n";
        return "list","func","alex";
    } elsif (defined wantarray()) {
        print "In scalar context\n";
        return "scalar";
    } else {
        print "In void context \n";
        return 0;
    }

}

$a = mysub();
print "$a \n";

@a = mysub();
print "@a \n";

mysub();
