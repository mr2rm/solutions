<?php
$s = readline();
for ($i = 0; $i < strlen($s); $i++)
    echo str_repeat($s[$i], $i) . substr($s, $i) . "\n";
?>
