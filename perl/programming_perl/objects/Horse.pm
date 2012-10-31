package Horse;
    

sub new {
    my $this = shift;
    my $class = ref($this) || $this;
    my $self = {
        color   => "bay",
        legs    => 4,
        owner   => undef,
        @_,
    };

    bless ($self,$class);
    return $self;
}

1;# make requrie happy
