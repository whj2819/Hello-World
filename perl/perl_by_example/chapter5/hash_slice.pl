#!/usr/bin/perl

%officer = (
    "NAME"    => "Tom Savage",
    "SSN"     => "510-22-3456",
    "DOB"     => "05/19/66"
);

@info = qw(Marine Captain 50000);
@officer{'BRANCH','TITLE','SALARY'} = @info;

@sliceinfo = @officer{'NAME','BRANCH','TITLE'};

print "The new values from the hash slice are @sliceinfo \n\n";
print "The hash now looks like this:\n";

foreach $key ('NAME','SSN','DOB','BRANCH','TITLE','SALARY') {
    printf "Key:%-10s Value:%-15s \n",$key,$officer{$key};
}
