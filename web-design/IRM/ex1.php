<?php
$m = 29; //до какого числа выводим
$p = 19; //число колонок
$c=9; //кратное число
$k=1; //счетчик для вывода
$r=$m/10;//число строк
$d=$m/$p;
$t=gettype($d);
$g=0;
if($t!='integer')
    $g=$p*((int)$d+1)-$m+1;
echo '<table border="1">';
for ($tr=1; $tr<=(int)$r+1; $tr++){
        echo '<tr>';//выводим строки
        for ($td=1; $td<=$p; $td++){
            if($k<=$m){//выводим до числа m включительно
                if($k!=$m)//если это не последнее число
                    if($k % $c == 0)//раскрашиваем то что кратно числу c
                        echo '<td style="color:white;background-color:green;">'. $k++ .'</td>';
                    else echo '<td>'. $k++ .'</td>';
                else{ //иначе если последнее число
                    if($k % $c == 0)//раскрашиваем то что кратно числу c
                        echo '<td style="color:white;background-color:green;" colspan="'. $g .'" align="center">'. $k++ .'</td>';
                    else echo '<td style="color:white;background-color:blue;" colspan="'. $g .'" align="center">'. $k++ .'</td>';}}}//выводим 
        echo '</tr>';}
echo '</table>';
?>
