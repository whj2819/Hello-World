package average;

sub ave {
    my(@grades) = @_;
    my($num_of_grades) = $#grades + 1;

    foreach $grade (@grades) {
        $total += $grade;
    }
    $total/$num_of_grades; # What gets returned
}

1; # Make sure the file returns true or require will not succeed!
