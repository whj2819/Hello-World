#!/usr/bin/perl

#
# Usage:
#   require "pwd.pl";
#   &initpwd;
#   ...
#   &chdir($newdir);
#

package pwd;
sub main'initpwd {
    if ( $ENV{'PWD'} ) {
        local($dd, $di) = stat('.');
        local ($pd, $pi) = stat( $ENV{'PWD'} );

        return if $di == $pi && $dd == $pd;
    }
    chop( $ENV{'PWD'} = `pwd`);
}

sub main'chdir {
    local ($newdir) = shift;
    if (chdir $newdir) {
        if ($newdir =~ m#^/#) {
            $ENV{'PWD'} = $newdir;
        } else {
            local(@curdir) = split(m#/#, $ENV{'PWD'});
            @curdir = '' unless @curdir;
            foreach $component (split(m#/#, $newdir)) {
                next if $component eq '.';
                pop(@curdir), next if $component eq '..';
            }
            $ENV{'PWD'} = join('/', @curdir) || '/';
        }
    } else {
        0;
    }
}


1;
