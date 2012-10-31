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

sub clone {
    my $model = shift(@_);
    print "$model------ @_ \n";
    my $self = $model->new(%$model,@_);

    while (my($k,$v) = each %$model) {
        print "++++\$k:$k,\$v:$v \n";
    }

    return $self;
}

sub __print {

    my @param = @_;

    print "___ @param \n";
}



1;# make requrie happy

