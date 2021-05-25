<?php
class Italic extends RegexRule
{
    public function rule()
    {
        return ['/\*(.+)\*/U', '/_(.+)_/U'];
    }

    public function replacement()
    {
        return '<i>$1</i>';
    }
}
