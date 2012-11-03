package Bug;

use strict;

sub new {
    print "$_[0],$_[1],$_[2],$_[3] \n\n";
    bless {
        _id => $_[1],
        _type => $_[2],
        _descr => $_[3],
    },$_[0];
}


=pon
sub new {
    my $class = $_[0];
    my $objref = {
        _id => $_[1],
        _type => $_[2],
        _descr => $_[3],
    };
    bless $objref,$class;
    print "$_[0],$_[1],$_[2],$_[3] \n\n";
    return $objref;
}

=cut
1;# make require happy
