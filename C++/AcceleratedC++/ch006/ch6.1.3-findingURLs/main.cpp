#include <vector>
#include <iostream>
#include <string>
#include <cctype>
#include "furls.h"
#include "prettyprint.h"

int main(int argc, const char * argv[]) {

    std::vector<std::string> urls;
    const std::string text = 
    "some kinf of text http://www.acceleratedcpp.com more text here. Some other text here. Then here there is a websire https://www.google.com and then some other text. Now some more websites: https://stackoverflow.com/ :) https://www.haskell.org/ https://www.python.org/ :o https://www.php.net/ >.< https://www.ruby-lang.org/en/ https://golang.org/ ?_## The quick brown fox. $$ https://someKindOfWebsite O_o httpHelloWorld://badabing!"
    ;

    urls = find_urls(text);
    printv(urls, true);
}