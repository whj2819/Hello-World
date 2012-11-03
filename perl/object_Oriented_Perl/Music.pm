package CD::Music;
use strict;

sub new {
    my ($class) = @_;

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


sub name {
    $_[0] -> {_name}
);

sub artist {
    $_[0] ->{_artist}
}

sub publisher{
    $_[0] ->{_publisher}
}

sub ISBN{
    $_[0] ->{_ISBN}
}

sub tracks{
    $_[0] ->{_tracks}
}
