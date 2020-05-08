<?php
class Code extends RegexRule
{
    public function rule()
    {
        return  '/`(.+)`/U';
    }

    public function replacement()
    {
        return '<code>$1</code>';
    }
}
