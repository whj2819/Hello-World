use Employee;
use warnings;
use strict;


my ($name, $extension, $address, $basepay, $employee);

print "Enter the employee's name.";
chomp($name = <STDIN>);

print "Enter the employee's phone extension.";
chomp($extension = <STDIN>);


print "Enter the employee's phone address.";
chomp($address= <STDIN>);

print "Enter the employee's phone basepay.";
chomp($basepay= <STDIN>);

$employee = Employee->new(
                            Name    => $name,
                            Address => $address,
                            Extension => $extension,
                            PayCheck => $basepay,
                        );
$employee->get_status;
