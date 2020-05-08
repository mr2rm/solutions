<?php

abstract class RegexRule implements RegexRuleInterface
{
    public function parse($content)
    {
        return preg_replace($this->rule(), $this->replacement(), $content);
    }

    abstract public function replacement();
}
