#include <iostream>
#include <string>
#include <regex>


using namespace std;

auto make_regex = [](const string &txt)
{
    return regex(txt);
};

auto make_match = []()
{
    return smatch();
};

int main(int argc, char const *argv[])
{
    using namespace std::literals::string_literals;
    auto str = "neir:automata"s;

    return 0;
}
