<?php
if (isset($_GET['a']) && isset($_GET['b']) && isset($_GET['op'])){
    $a = $_GET['a'];
    $b = $_GET['b'];
    $op = $_GET['op'];
    switch ($op){
        case 'add':
            $c = $a+$b;
            print "$a+$b=$c";
            break;
        case 'sub':
            $c = $a-$b;
            print "$a-$b=$c";
            break;
        case 'mul':
            $c = $a*$b;
            print "$a*$b=$c";
            break;
        case 'div':
            if($b==0) print 'unbelieveble';
            else{
                $c=$a/$b;
                print "$a/$b=$c";}
            break;
        default: print 'no';}}
else print "No params!";
?>
