<?php
class Link extends RegexRule
{
    public function rule()
    {
        return '/\[(.*)\]\((.*)\)/';
    }

    public function replacement()
    {
        return '<a href="$2">$1</a>';
    }
}
