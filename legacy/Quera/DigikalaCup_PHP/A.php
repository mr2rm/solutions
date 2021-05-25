<?php
$line = readline();
list($y, $m, $d) = explode('/', $line);
$x = min($m - 1, 6) * 31;
$y = max($m - 1 - 6, 0) * 30;
$res = 366 - ($x + $y + $d);
echo $res;
