package Critter;

sub spawn {
    my $class = shift;
    print "\$class:$class \n";
    my $self = {};
    bless ($self,$class);
    return $self;
}

1;# make require happy
