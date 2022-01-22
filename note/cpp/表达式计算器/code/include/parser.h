#ifndef _PARSER_H_
#define _PARSER_H_

class Scanner;
class Node;

enum STATUS
{
    STATUS_OK,
    STATUS_ERROR,
    STATUS_QUIT,
};

class Parser
{
public:
    Parser(Scanner& scanner);
    void Parse();
    Node* Expr();             // 解析成表达式
    Node* Term();             // 解析成项
    Node* Factory();          // 解析成因子
    double Calculate() const;
private:
    Scanner& scanner_;
    Node* tree_;       // 表达式树
    STATUS status_;
    
};

#endif // !_PARSER_H_