package Critter;

sub spawn {
    my $this = shift;
    my $class = ref($this) || $this;# Object or class name
    print "\$class:$class \n";
    my $self = {};
    bless ($self,$class);
    return $self;
}


1;# make require happy
