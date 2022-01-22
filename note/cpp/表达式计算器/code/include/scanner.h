#ifndef _SCANNER_H_
#define _SCANNER_H_

#include <string>

enum EToken
{
    TOKEN_END,
    TOKEN_ERROR,
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_LPARENTHESIS,
    TOKEN_RPARENTHESIS,
    TOKEN_IDENTIFIER,
    TOKEN_ASSIGN
};

class Scanner
{
public:
    Scanner(const std::string& buf);
    void Accept();         // 每次扫描一个字符
    double Number() const; // 不改变数据成员，只是返回其值
    EToken Token() const;
private:
    void SkipWhite();      // 跳过空字符
    const std::string buf_;
    unsigned int curPos_;  // 当前扫描到的位置
    EToken token_;         // 当前状态
    double number_;
};

#endif // !_SCANNER_H_