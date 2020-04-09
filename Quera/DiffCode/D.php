<?php
[$n, $m] = explode(' ', readline());
$markCount = array_fill(0, $n + 1, array_fill(0, $m + 1, 0));

$score = [0, 0];
$lineCount = 2 * $n * $m - $n - $m;

$turn = 0;
while ($lineCount--) {
    $cnt = 0;
    [$a, $b, $c, $d] = explode(' ', readline());
    
    if ($a == $c) {
        if ($b > $d) [$b, $d] = [$d, $b];
        $markCount[$a][$b]++; $markCount[$a - 1][$b]++;
        if ($markCount[$a][$b] == 4)                    $cnt++;
        if ($a > 1 && $markCount[$a - 1][$b] == 4)      $cnt++;
    } else {
        if ($a > $c) [$a, $c] = [$c, $a];
        $markCount[$a][$b]++; $markCount[$a][$b - 1]++;
        if ($markCount[$a][$b] == 4)                    $cnt++;
        if ($b > 1 && $markCount[$a][$b - 1] == 4)      $cnt++;
    }
    
    if ($cnt == 0)  $turn = 1 - $turn;
    else            $score[$turn] += $cnt;
}
echo implode(" ", $score);
?>
