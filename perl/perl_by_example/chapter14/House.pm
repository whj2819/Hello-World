package House;

sub new {
    my $class = shift;
    my ($owner, $salary, $style) = @_;
    my $ref = {
        Owner => $owner,
        Price => $salary,
        Style => $style,
    };
    bless ($ref, $class);

    return $ref;
}

sub display {
    my $self = shift;

    foreach $key (@_) {
        print "$key: $self->{$key} \n";
    }
}

1;
