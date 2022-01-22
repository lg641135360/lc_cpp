#include "node.h"

#include <iostream>
#include <math.h>

double NumberNode::Calc() const
{
    return number_;
}

// 释放两个数据成员
BinaryNode::~BinaryNode()
{
    delete left_;
    delete right_;
}

// 释放数据成员
UnaryNode::~UnaryNode()
{
    delete child_;
}

double AddNode::Calc() const
{
    return left_->Calc()+right_->Calc();
}

double SubNode::Calc() const
{
    return left_->Calc()-right_->Calc();
}

double MultiplyNode::Calc() const
{
    return left_->Calc()*right_->Calc();
}

double DivideNode::Calc() const
{
    // 判断除数是否为0
    double divisor = right_->Calc();
    if(divisor != 0.0)
        return left_->Calc()/right_->Calc();
    else 
    {
        std::cout<<"ERROR: Divisor by zero"<<std::endl;
        return HUGE_VAL;
    }
}

double UMinusNode::Calc() const
{
    return -child_->Calc();    
}