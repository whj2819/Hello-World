#!/usr/bin/perl

use Text::Tabs;

#$tabstop = 4;

while (<>) {
    print unexpand $_,"\n";
}

=pon
$tabstop = 4;
@line_with_tabs = "This		is 	a test";
@line_without_tabs ="alextest";
@expanded_lines = expand(@line_with_tabs);
@tabulated_lines = unexpand(@line_without_tabs);

print "__ expanded lines @expanded_lines \n";
print "-- unexpanded lines @tabulated_lines \n";

print @expanded_lines,"\n";
print @tabulated_lines,"\n";
=cut
