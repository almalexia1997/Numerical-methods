<?php
mysql_connect("localhost", "student","student") or die(mysql_error);
mysql_select_db("student");

$r = mysql_query("SELECT page_id, page_name, page_text FROM site WHERE page_id = {$_GET['page_id']}");
$row = mysql_fetch_array($r);
$title = $row['page_name'];
$body = $row['page_text'];

$r = mysql_query("SELECT page_id, page_name FROM site ORDER BY page_weight");
$menu = "<ul>";
while($s = mysql_fetch_array($r)){
$menu.="<li><a href = '?page_id={$s['page_id']}'>{$s['page_name']}</a></li>";
}
$menu.="</ul>";
?>

<html>
<head>
<title><?= $title;?></title>
</head>
<body>
<menu>
<?= $menu; ?>
</menu>
<content>
<?= $body; ?>
</body>
</html>
