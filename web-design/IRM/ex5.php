<?php
mysql_connect("localhost", "root","") or die(mysql_error);
mysql_select_db("student");
echo "СОДЕРЖИМОЕ СЧЕТА";
$r = mysql_query("SELECT goods, price, quantity, bid FROM bill_content");
echo '<table border="1">';
echo '<tr>
        <th>goods</th>
        <th>price</th>
        <th>quantity</th>
        <th>bid</th>
      </tr>';
while ($line = mysql_fetch_array($r, MYSQL_ASSOC)) {
  echo "<tr>";
  foreach ($line as $col_value) {
      echo "<td>$col_value</td>\n";}
  echo "</tr>";}
echo '</table><br>';

echo "СЧЕТА";
$r2 = mysql_query("SELECT num, bdate, name, (SELECT SUM(price) from bill_content where bill_content.bid=bill.bid) from bill");
echo '<table border="1">';
echo '<tr>
        <th>num</th>
        <th>bdate</th>
        <th>name</th>
        <th>sum</th>
      </tr>';
while ($line2 = mysql_fetch_array($r2, MYSQL_ASSOC)) {
  echo "<tr>";
  foreach ($line2 as $col_value2) {
      echo "<td>$col_value2</td>\n";}
  echo "</tr>";}
echo '</table><br>';

echo "ЗАДОЛЖЕННОСТИ ПО СЧЕТАМ";
$r3 = mysql_query("SELECT num, name, (SELECT SUM(price) from bill_content where bill_content.bid=bill.bid) as count, (SELECT SUM(summa) from payment where payment.bid=bill.bid) as pay, (SELECT count-pay) from bill");
echo '<table border="1">';
echo '<tr>
        <th>num</th>
        <th>name</th>
        <th>sum</th>
        <th>pay</th>
        <th>debt</th>
      </tr>';
while ($line3 = mysql_fetch_array($r3, MYSQL_ASSOC)) {
  echo "<tr>";
  foreach ($line3 as $col_value3) {
      echo "<td>$col_value3</td>\n";}
  echo "</tr>";}
echo '</table>';
?>
