package House;

sub new {
    my $class = shift;
    my $ref = {
        Owner => undef,
        Price => undef,
    };
    bless ($ref, $class);

    return $ref;
}

sub set_owner {
    my $self = shift;
    $self->{Owner} = shift;
}

sub display_owner {
    my $self = shift;
    print $self->{Owner}, "\n";
}


1;
