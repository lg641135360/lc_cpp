#include "parser.h"

#include "scanner.h"
#include "node.h"

#include <cassert>

Parser::Parser(Scanner &scanner) : scanner_(scanner), tree_(0)
{
}

void Parser::Parse()
{
    Expr(); // 对表达式进行解析
}

Node *Parser::Expr()
{
    Node *node = Term();
    EToken token = scanner_.Token();
    if (token == TOKEN_PLUS)
    {
        scanner_.Accept();
        Node *nodeRight = Expr();
        node = new AddNode(node, nodeRight);
    }
    else if (token == TOKEN_MINUS)
    {
        scanner_.Accept();
        Node *nodeRight = Expr();
        node = new SubNode(node, nodeRight);
    }
    return node;
}

Node *Parser::Term()
{
    return 0;
}

Node *Parser::Factory()
{
    return 0;
}

double Parser::Calculate() const
{
    assert(tree_ != nullptr);
    return tree_->Calc(); // 求根节点的值
}
