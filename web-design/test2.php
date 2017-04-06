<?php
if(isset($_GET["number"]))
$i=$_GET["number"];
else $i=0;
print "<a href = '?number='".($i+1)."'>$i</a>";
?>
