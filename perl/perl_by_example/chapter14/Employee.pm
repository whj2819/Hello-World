package Employee;

use Carp;


sub new {
    my $class = shift;
    my (%params) = @_;

    my $objptr =  {
        Name    => $params{Name} || croak ("No name assigned"),
        Extension => $params{Extension},
        Address => $params{Address},
        PayCheck    => $params{"PayCheck"} || croak("No pay assigned"),
        ( (defined $package{IdNum}) ? (IdNum => $package{IdNum}):
            (IdNum => "Employee's id was not provided!") ),
    };
    return bless($objptr, $class);
}

sub get_status {
    my $self = shift;

    while ( ($key, $value) = each %$self) {
        print $key, " = ", $value, "\n";
    }
    print "\n";
}

1;
