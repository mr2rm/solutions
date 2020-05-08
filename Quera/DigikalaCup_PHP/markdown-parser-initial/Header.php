<?php
class Header extends RegexRule
{
    public function rule()
    {
        return '/#{1,6}\s*(.+)/';
    }

    public function replacement()
    {
        return '<h3>$1</h3>';
    }
}
