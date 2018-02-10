<html>
<head> <title>Calc</title></head>
<body>
<form action="" method="POST">
  <input type="text" name="a">
  <select name="op">
    <option value="add">+</option>
    <option value="sub">-</option>
    <option value="mul">*</option>
    <option value="div">/</option>
  </select>
  <input type="text" name="b">
  <input type="submit" value="=">
</form>
</body>
</html>
<?php
if (isset($_POST['a']) && isset($_POST['b']) && isset($_POST['op'])){//если параметры определены
    $a = $_POST['a'];//сохраняем их в переменных
    $b = $_POST['b'];
    $op = $_POST['op'];
    if(!is_numeric($a) or !is_numeric($b)) print "uncorrect parametrs.";
    else{
        switch ($op){
            case 'add'://если $op==add
                $c = $a+$b;
                print "$a+$b=$c<br />Enter new parametrs.";
                break;
            case 'sub'://если $op==sub
                $c = $a-$b;
                print "$a-$b=$c<br />Enter new parametrs.";
                break;
            case 'mul'://если $op==mul
                $c = $a*$b;
                print "$a*$b=$c<br />Enter new parametrs.";
                break;
            case 'div'://если $op==div
                if($b==0) print 'Результат обработается через 10 миллиардов лет<br />Enter new parametrs.';
                else{
                    $c=$a/$b;
                    print "$a/$b=$c<br />Enter new parametrs.";}
                break;
            default: print 'no';}}}//$op не равно ни одному из значений
else print "Enter parametrs.";
?>
