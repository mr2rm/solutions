<?php
class Bold extends RegexRule
{
    public function rule()
    {
        return ['/\*\*(.+)\*\*/U', '/__(.+)__/U'];
    }

    public function replacement()
    {
        return '<b>$1</b>';
    }
}
