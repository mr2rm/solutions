<?php

function getButton($text, $number = null)
{
    $button = ['text' => $text];
    if (!is_null($number))
        $button['number'] = $number;
    return $button;
}

function getPaginationButtons($total_items, $per_page, $current_page)
{
    $last_page = floor($total_items / $per_page) + ($total_items % $per_page == 0 ? 0 : 1);
    $res = [];

    if ($current_page != 1)
        array_push($res, getButton('prev', $current_page - 1));
    array_push($res, getButton('1', 1));
    if ($current_page - 2 - 1 > 1)
        array_push($res, getButton('...'));

    $l = max($current_page - 2, 2);
    $r = min($current_page + 2, $last_page - 1);
    for ($i = $l; $i <= $r; ++$i)
        array_push($res, getButton("$i", $i));

    if ($last_page - $current_page - 2 > 1)
        array_push($res, getButton('...'));
    array_push($res, getButton("$last_page", $last_page));
    if ($current_page != $last_page)
        array_push($res, getButton('next', $current_page + 1));

    return $res;
}

function renderPagination($pagination_template, $total_items, $per_page, $current_page, $base_url)
{
    $pages = getPaginationButtons($total_items, $per_page, $current_page);
    $html = '';
    foreach ($pages as $page) {
        $page['text'] = str_replace(['prev', 'next'], ['&laquo;', '&raquo;'], $page['text']);
        if (in_array($page['text'], ['&laquo;', '...', '&raquo;'])) {
            $html .= '<li class="page-item">
              <a class="page-link" href="' . (isset($page['number']) ? $base_url . $page['number'] : '#') . '">
                <span aria-hidden="true">' . $page['text'] . '</span>
              </a>
            </li>';
        } else {
            $html .= '<li class="page-item' . ($page['number'] == $current_page ? ' active' : '') . '"><a class="page-link" href="' . $base_url . $page['number'] . '">' . $page['number'] . '</a></li>';
        }
    }

    return str_replace('{{ @pages }}', $html, $pagination_template);
}
