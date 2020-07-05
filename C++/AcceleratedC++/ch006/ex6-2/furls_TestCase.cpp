// Let Catch provide main():
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

#include <vector>
#include "furls.h"

TEST_CASE( "A phrase containing an URL") {
    const std::string url = "http://www.acceleratedcpp.com";
    const std::string text = "some kinf of text http://www.acceleratedcpp.com";
    REQUIRE(find_urls(text)[0] == url);
}

TEST_CASE( "several URLs") {
    std::vector<std::string> urls;
    const std::string text = 
    "some kinf of text http://www.acceleratedcpp.com more text here. Some other text here. Then here there is a websire https://www.google.com and then some other text. Now some more websites: https://stackoverflow.com/ :) https://www.haskell.org/ https://www.python.org/ :o https://www.php.net/ >.< https://www.ruby-lang.org/en/ https://golang.org/ ?_## The quick brown fox. $$ https://someKindOfWebsite O_o httpHelloWorld://badabing!";

    urls = find_urls(text);

    REQUIRE(find_urls(text)[0] == "http://www.acceleratedcpp.com");
    REQUIRE(find_urls(text)[1] == "https://www.google.com");
    REQUIRE(find_urls(text)[2] == "https://stackoverflow.com/");
    REQUIRE(find_urls(text)[3] == "https://www.haskell.org/");
    REQUIRE(find_urls(text)[4] == "https://www.python.org/");
    REQUIRE(find_urls(text)[5] == "https://www.php.net/");
    REQUIRE(find_urls(text)[6] == "https://www.ruby-lang.org/en/");
    REQUIRE(find_urls(text)[7] == "https://golang.org/");
    REQUIRE(find_urls(text)[8] == "https://someKindOfWebsite");
    REQUIRE(find_urls(text)[9] == "httpHelloWorld://badabing!");
}

TEST_CASE( "no URL") {
    std::vector<std::string> urls;
    const std::string text = 
    "some kinf of text more text here. Some other text here. Then here there is a websire and then some other text. Now some more websites: :) :o  >.< ?_## The quick brown fox. $$ O_o ";

    urls = find_urls(text);

    REQUIRE(find_urls(text).empty() == true);
}
