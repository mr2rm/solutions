<?php
class Image extends RegexRule
{
    public function rule()
    {
        return '/\!\[(.*)\]\((.*)\)/';
    }

    public function replacement()
    {
        return '<img src="$2" alt="$1">';
    }
}
