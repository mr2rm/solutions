<?php

class MarkdownParser
{
    public $rules = [];

    public function __construct()
    {
        $default_rules = [
            'Header',
            'Bold',
            'Italic',
            'Image',
            'Link',
            'Code',
            'HorizontalRule'
        ];
        foreach ($default_rules as $rule) {
            if (class_exists($rule)) {
                $this->rules[] = new $rule();
            }
        }
    }

    public function addRule($rule)
    {
        $this->rules[] = $rule;
    }

    public function render($content)
    {
        foreach ($this->rules as $rule) {
            $content = $rule->parse($content);
        }

        return $content;
    }
}
