package House;

sub new {
    my $class = shift;
    my ($owner, $salary) = @_;
    my $ref = {
        Owner => $owner,
        Price => $salary,
    };
    bless ($ref, $class);

    return $ref;
}

sub display_object {
    my $self = shift;

    while ( ($key, $value) = each %$self) {
        print "$key: $value \n";
    }
}


1;
