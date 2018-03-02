<?php
header('Content-Type: text/html; charset=utf-8');
if(isset($_GET["number"])) $i=$_GET["number"];
else $i=0;
if(isset($_GET["page"])) $p=$_GET["page"];
else $p=1;
if(isset($_GET["all"])) $a=$_GET["all"];
else $a="yes";//yes - по умолчанию, означает режим "все книги"
if(isset($_GET["card"])) $c=$_GET["card"];
else $c=0;
$x = $i - floor($i);//десятичная часть от number (нужна для проверки на корректность переданных параметров)
//ПРОВЕРЬ КОРРЕКТНОСТЬ ДЛЯ PAGE
$j=$i*10+1;//индекс первой страницы в очередном number
$h=$j+9;//индекс последней страницы в очередном number
$z=$p*10;//последний номер книги на странице результатов
$k=$z-9;//первый номер книги на странице
$s=0;//количество всех книг в БД (в зависимости от режима)
mysql_connect("localhost", "root","") or die(mysql_error);
mysql_select_db("student");
// По умолчанию сортировка по id, по возрастанию
$orderby = 'id';
$sort = 'ASC';
if (isset($_GET['orderby']) and isset($_GET['sort'])) {
  if (in_array($_GET['orderby'], array('id','name_book','author'))) $orderby=$_GET['orderby'];
  if (in_array($_GET['sort'], array('ASC','DESC'))) $sort=$_GET['sort'];}
if($a=='yes') $r = mysql_query("SELECT id, name_book, author FROM library ORDER BY ".$orderby." ".$sort);
else $r = mysql_query("SELECT id, name_book, author FROM library WHERE issued='NULL' ORDER BY ".$orderby." ".$sort);
if($i>=0 and is_numeric($i) and $x==0){
  //СПИСОК КНИГ
  if ($c==0) {
	  echo '<table border="1">';
	  echo '<tr>';
	  if ($sort=='ASC') {
	    $tmp='DESC';
	    $image='down.gif';} 
	  else {
	    $tmp='ASC';
	    $image='up.gif';}
	  if ($orderby == 'id')
	    echo '<th><a href="'.$_SERVER['PHP_SELF'].'?orderby=id&sort='.$tmp.'&number='.$i.'&page='.$p.'&all='.$a.'">№</a>&nbsp;<img src="images/'.$image.'" alt="" /></th>';
	  else
	    echo '<th><a href="'.$_SERVER['PHP_SELF'].'?orderby=id&sort=ASC&number='.$i.'&page='.$p.'&all='.$a.'">№</a></th>';
	  if ($orderby=='name_book')
	    echo '<th><a href="'.$_SERVER['PHP_SELF'].'?orderby=name_book&sort='.$tmp.'&number='.$i.'&page='.$p.'&all='.$a.'">name</a>&nbsp;<img src="images/'.$image.'" alt="" /></th>';
	  else
	    echo '<th><a href="'.$_SERVER['PHP_SELF'].'?orderby=name_book&sort=ASC&number='.$i.'&page='.$p.'&all='.$a.'">name</a></th>';
	  if ($orderby == 'author')
	    echo '<th><a href="'.$_SERVER['PHP_SELF'].'?orderby=author&sort='.$tmp.'&number='.$i.'&page='.$p.'&all='.$a.'">author</a>&nbsp;<img src="images/'.$image.'" alt="" /></th>';
	  else
	    echo '<th><a href="'.$_SERVER['PHP_SELF'].'?orderby=author&sort=ASC&number='.$i.'&page='.$p.'&all='.$a.'">author</a></th>';
	  echo '</tr>'."\n";
	  while ($line = mysql_fetch_array($r, MYSQL_ASSOC)) {
	      ++$s;//УЗНАЕМ КОЛИЧЕСТВО ВСЕХ КНИГ В БД ПО ИСТЕЧЕНИЮ ЦИКЛА
	      if($s<=$z and $s>=$k){
	       	  echo '<tr>';
			  echo '<td>'.$line['id'].'</td>'."\n";
			  echo '<td><a href="?number='.$i.'&page='.$p.'&all='.$a.'&card='.$line['id'].'">'.$line['name_book'].'</td>'."\n";
			  echo '<td>'.$line['author'].'</td>'."\n";   
			  echo '</tr>'."\n";}}
	  echo '</table><br>';
	  $f=$s/10;
	  $g=(int)$f+1;
	  print "Страницы: ";
	  if($i!=0) print "<a href = '?orderby=".$orderby."&sort=".$sort."&number=".($i-1)."&page=".($j-1)."&all=".$a."'> << </a>";
	  for(;$j<=$g;$j++){
	    if($j==$p) print "$j ";
	    else print "<a href='?orderby=".$orderby."&sort=".$sort."&number=".$i."&page=".$j."&all=".$a."'>".$j." "."</a>";}
	  if(gettype($g/10)=='integer') print "<a href = '?orderby=".$orderby."&sort=".$sort."&number=".($i+1)."&page=".$j."&all=".$a."'> >> </a>";}
  
  else {
	  //КАКРТОЧКА КНИГИ
	  $t = mysql_query("SELECT library.id, name_file, name_book, author, ldate, annotation, themes.name_theme FROM library INNER JOIN themes WHERE library.theme=themes.id and library.id=".$c);
	  echo '<table border="1">';
	  echo '<tr>
	 	 	<th>image</th>		
	        <th>name</th>
	        <th>author</th>
	        <th>year</th>
	        <th>annotation</th>
	        <th>genre</th>
	      </tr>';
	  while ($linet = mysql_fetch_array($t, MYSQL_ASSOC)) {
	  	echo '<tr>';
		echo '<td><img src="images/'.$linet['name_file'].'" width="260" height="400" alt="" /></td>'."\n";
		echo '<td>'.$linet['name_book'].'</td>'."\n";
		echo '<td>'.$linet['author'].'</td>'."\n";  
		echo '<td>'.$linet['ldate'].'</td>'."\n";
		echo '<td>'.$linet['annotation'].'</td>'."\n";
		echo '<td>'.$linet['name_theme'].'</td>'."\n";
		echo '</tr>'."\n";} 
	  echo '</table><br>';
	  print "<a href='?number=".$i."&page=".$p."&all=".$a."'>Назад</a>";}}
else print "uncorrect parametr.";
print "<br><a href = '?number=".$i."&page=".$p."&all=no'> Книги в наличии </a>";
print "&nbsp<a href = '?number=".$i."&page=".$p."&all=yes'> Все книги </a>";
?>
