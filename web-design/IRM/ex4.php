<?php
    if(isset($_GET["number"])) $i=$_GET["number"];
    else $i=0;
    $x = $i - floor($i);
    $j=$i*10+1;
    $h=$j+9;
    if($i>=0 and is_numeric($i) and $x==0){
        //print "<a href = '?number=".($i+1)."'>$i</a>";
        if($i!=0) print "<a href = '?number=".($i-1)."'> << </a>";
        for(;$j<=$h;$j++)
            print "$j ";
        print "<a href = '?number=".($i+1)."'> >> </a>";}
    else print "uncorrect parametr."
?>
