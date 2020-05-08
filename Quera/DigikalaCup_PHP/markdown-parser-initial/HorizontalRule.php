<?php
class HorizontalRule extends RegexRule
{
    public function rule()
    {
        return  '/-{3,}/';
    }

    public function replacement()
    {
        return '<hr>';
    }
}
