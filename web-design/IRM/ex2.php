<?php
$n_max = 10;
$m_max = 10;
$n_min = 1;
$m_min = 1;
$x = 2;//для строки x
$y = 3;//для столбца y
$k = 2;//возводим число в степень k
$p = array($x => array($y => $k));
echo '<table border="1">';
for ($tr=$n_min; $tr<=$n_max; $tr++){
    echo '<tr>';
    for ($td=$m_min; $td<=$m_max; $td++)
        if($tr==$x and $td==$y)
            echo '<td style="color:white;background-color:blue;">'. pow($tr*$td,$p[$x][$y]) .'</td>'; 
        else echo '<td>'. $tr*$td .'</td>';
    echo '</tr>';}
echo '</table>';
?>
