<?php
function octetify($i, $cnt, $res)
{
    global $str;
    if ($i == strlen($str)) {
        if ($cnt == 4)
            echo "{$res}\n";
        return;
    }

    $cur = "";
    for ($j = $i; $j < strlen($str); $j++) {
        $cur .= $str[$j];
        if (($cur[0] == '0' && $j > $i) || (int)$cur >= 256)
            return;
        $new_res = $i == 0 ? $cur : "{$res}.{$cur}";
        octetify($j + 1, $cnt + 1, $new_res);
    }
}

$str = readline();
octetify(0, 0, "");
