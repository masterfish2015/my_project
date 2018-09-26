/**
 * SyntaxHighlighter
 * http://alexgorbatchev.com/SyntaxHighlighter
 *
 * SyntaxHighlighter is donationware. If you are using it, please donate.
 * http://alexgorbatchev.com/SyntaxHighlighter/donate.html
 *
 * @version
 * 0.0.1 (2017-4-4)
 * 
 * @copyright
 * Copyright (C) 2004-2017 Dachuan Lin.
 *
 * @license
 * Dual licensed under the MIT and GPL licenses.
 */
;
(function () {
    // CommonJS
    typeof (require) != 'undefined' ? SyntaxHighlighter = require('shCore').SyntaxHighlighter: null;

    function Brush() {
        // Copyright 2017 Dachuan Lin

        var datatypes = '';

        var keywords = '.TITLE';

        var functions = '';

        this.regexList = [
            { regex: SyntaxHighlighter.regexLib.singleLineCComments, css: 'comments' }, // one line comments
            { regex: SyntaxHighlighter.regexLib.multiLineCComments, css: 'comments' }, // multiline comments
            { regex: SyntaxHighlighter.regexLib.doubleQuotedString, css: 'string' }, // strings
            { regex: SyntaxHighlighter.regexLib.singleQuotedString, css: 'string' }, // strings
            { regex: /^ *#.*/gm, css: 'preprocessor' },
            { regex: new RegExp(this.getKeywords(datatypes), 'gm'), css: 'color1 bold' },
            { regex: new RegExp(this.getKeywords(functions), 'gm'), css: 'functions bold' },
            { regex: new RegExp(this.getKeywords(keywords), 'gm'), css: 'keyword bold' }
        ];
    };

    Brush.prototype = new SyntaxHighlighter.Highlighter();
    Brush.aliases = ['ngspice'];

    SyntaxHighlighter.brushes.ngspice = Brush;

    // CommonJS
    typeof (exports) != 'undefined' ? exports.Brush = Brush: null;
})();
