package Horse;
    

sub new {
    my $this = shift;
    my $class = ref($this) || $this;
    my $self = {@_};

    bless ($self,$class);
    return $self;
}

1;# make requrie happy
