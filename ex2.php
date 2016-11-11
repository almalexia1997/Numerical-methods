<?php
//========================================ПРЕАМБУЛА=========================================================
//Кодировка
header('Content-Type: text/html; charset=utf-8');

//Свзяваемся с БД
$link = mysql_connect("localhost", "student","student") or die('Не удалось соединиться: ' . mysql_error());
mysql_select_db("student");

//Парметры поля, сортировки и страницы
$field = isset($_GET['field'])? $_GET['field'] : '';
$sort = isset($_GET['sort'])? $_GET['sort'] : 'asc';
$page = isset($_GET['page'])? $_GET['page']-1 : 0;
$ident = isset($_GET['ident'])? $_GET['ident'] : '';

//Создаем основной запрос в БД
$q = "SELECT TableRus.id, TableRus.datet,TableRus.had, AvtorRus.fio, RubricaRus.NameRubric,TableRus.anons,TableRus.body FROM TableRus INNER JOIN AvtorRus ON(TableRus.avtor = AvtorRus.id) INNER JOIN RubricaRus ON(TableRus.rubric = RubricaRus.id) ";

//Производим сортировку полей
if (!empty($field)) {
  $q .= " ORDER BY $field $sort";
}

//================================================СТРАНИЦЫ================================================
//Разбивка на страницы
$a = mysql_query("SELECT COUNT(1) FROM TableRus");
$b = mysql_fetch_array( $a );
$total_rows=$b[0];
echo "общее число новостей: ", $total_rows, "<br>"; // выведет число строк

$per_page = 10;//количество записей на одной странице
$start=abs($page*$per_page);// вычисляем первый оператор для LIMIT
$num_pages=ceil($total_rows/$per_page);//сколько всего получится страниц

//создаем ссылки на страницы
for($i=1;$i<=$num_pages;$i++) {
  if ($i-1 == $page) {
    echo $i." ";
  } else {
    if (!empty($field) && !empty($sort)) { $fs = "&field=$field&sort=$sort"; } else { $fs =''; }
    echo '<a href="'.$_SERVER['PHP_SELF'].'?page='.$i.$fs.'">'.$i."</a> ";
  }
}
$q .= " LIMIT $start,$per_page";

//===================================================ТАБЛИЦА=====================================================

//Открываем таблицу

$result = mysql_query($q) or die('Запрос не удался: ' . mysql_error());;
echo '<table border="5" width="1900">';

//Вывод заголовков
echo '<tr>';
for ($i = 0, $L = mysql_num_fields($result); $i < $L; $i++) {
  $field = mysql_fetch_field($result, $i);
  $sort_rev = $sort=='asc' ? 'desc': 'asc';
  echo "<th><a href='?page=".($page+1)."&field={$field->name}&sort=$sort_rev'>", htmlspecialchars($field? $field->name : "[$i]"), '</a></th>';
}
echo '</tr>';

//Вывод новостей
while ($line = mysql_fetch_array($result, MYSQL_ASSOC)) {
  echo "\t<tr>\n";
  foreach ($line as $col_value) {
    //if(isset($id)==TRUE){
      //$sql=mysql_query("SELECT TableRus.id FROM TableRus WHERE TableRus.id = $ident");
      //$r=mysql_fetch_array($sql);
      //echo "$r";
    //}
    //else {
      echo "<td>$col_value</td>\n";
    //}
  }
  echo "</tr>\n";
}
//Закрываем таблицу
echo "</table>\n";

//=================================================ВЫВОД НОВОСТЕЙ==============================================




//================================================ЗАВЕРШАЕМ РАБОТУ============================================

// Освобождаем память от результата
mysql_free_result($result);

// Закрываем соединение
mysql_close($link);

//========================================================================================================
?> 


