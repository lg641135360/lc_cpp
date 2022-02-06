#include "stringutil.h"

void StringUtil::LTrim(string &s)
{
    string drops = " \t"; // 空格\t 表示空白字符
    s.erase(0, s.find_first_not_of(drops));
}

void StringUtil::RTrim(string &s)
{
    string drops = " \t";
    s.erase(s.find_last_not_of(drops) + 1);
}

void StringUtil::Trim(string &s)
{
    LTrim(s);
    RTrim(s);
}