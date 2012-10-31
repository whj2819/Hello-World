package Critter;

sub spawn {
    my $self = {};
    bless $self,"Critter";
    return $self;
}

1;# make require happy
