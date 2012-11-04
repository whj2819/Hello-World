package CD::Music;
use strict;


{
    my $_count = 0;

    sub get_count {
        $_count
    }

    sub new {
        my ($class) = @_;

        ++$count;
        bless {
            _name=> $_[1],
            _artist=> $_[2],
            _publisher=> $_[3],
            _ISBN=> $_[4],
            _tracks=> $_[5],
        _room=> $_[6],
        _shelf=> $_[7],
        _rating=> $_[8],
    },$class;
}

}
sub get_ name {
    $_[0] -> {_name}
);

sub get_artist {
    $_[0] ->{_artist}
}

sub get_publisher{
    $_[0] ->{_publisher}
}

sub get_ISBN{
    $_[0] ->{_ISBN}
}

sub get_tracks{
    $_[0] ->{_tracks}
}

sub set_location {
    my ($self,$shelf,$room) = @_;

    $self->{_room} = $room if $room;
    $self->{_shelf} = $shelf if $shelf;

    return ($self->{_room},$self->{_shelf});

}

sub set_rating {
    my ($self,$rating)  = @_;

    $self->{_rating} = $rating if defined $rating ;
    return $self->{_rating};
}


1; # make requires happy
