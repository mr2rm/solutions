<?php

spl_autoload_register(function ($class_name) {
    $file_path = __DIR__ . '/' . $class_name . '.php';
    if (is_file($file_path)) {
        include $file_path;
    }
});

$mp = new MarkdownParser();
echo $mp->render("
    # heading 1
    ##heading 2
    ###   heading 3
    ####  heading 4
    #####    heading 5
    #######heading 6
    x # heading 7
    ## heading 8 x
    **bold 1**
    __bold 2__ 
    x __bold 3__
    __bold 4__ x
    x **bold 5**
    **bold 6** x
    x__bold 7__x
    x**bold 8**x
    ___bold 9__
    __bold 10___
    ***bold 11**
    **bold 12***
    *italic 1*
    __italic 2__ 
    x __italic 3__
    __italic 4__ x
    x *italic 5*
    *italic 6* x
    x__italic 7__x
    x*italic 8*x
    ___italic 9__
    __italic 10___
    **italic 11*
    *italic 12**
    [Link to Google](https://google.com)
    [](https://google.com)
    [Link to Google]()
    []()
    ![Quera's Logo](https://cdn.quera.ir/images/logo/logo-q.0-3aee17faf53e.svg)
    ![](https://cdn.quera.ir/images/logo/logo-q.0-3aee17faf53e.svg)
    ![Quera's Logo]()
    ![]()
    `echo \"Hello, World!\";``echo`
    ---
    -----
    ----
    x --- y ---- z ----- w
    [# Link to Google](https://google.com)
    # ---
");
