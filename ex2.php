<?php

header('Content-Type: text/html; charset=utf-8');
$link = mysql_connect("localhost", "student","student") or die('Не удалось соединиться: ' . mysql_error());
mysql_select_db("student");
$result = mysql_query("SELECT TableRus.id, TableRus.datet,TableRus.had, AvtorRus.fio, RubricaRus.NameRubric,TableRus.anons,TableRus.body FROM TableRus INNER JOIN AvtorRus ON(TableRus.avtor = AvtorRus.id) INNER JOIN RubricaRus ON(TableRus.rubric = RubricaRus.id)") or die('Запрос не удался: ' . mysql_error());;

$rows = 2; // количество строк, tr
$cols = 7; // количество столбцов, td

//Выводим результаты в html
echo "<table> \n";
while ($line = mysql_fetch_array($result, MYSQL_ASSOC)) {
  echo "\t<tr>\n";
  foreach ($line as $col_value) {
    echo "\t\t<td>$col_value</td>\n";
  }
  echo "\t</tr>\n";
}
echo "</table>\n";

// Освобождаем память от результата
mysql_free_result($result);

// Закрываем соединение
mysql_close($link);

?>
