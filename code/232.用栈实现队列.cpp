/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    /** Initialize your data structure here. */
    // MyQueue() {

    // }
    
    /** Push element x to the back of queue. */
    // void push(int x) {
    //   s1.push(x);
    // }
    
    /** Removes the element from in front of queue and returns that element. */
    // int pop() {
    //   // 当输出栈空时，搬运
    //   if(s2.empty())
    //     inToOut();
    //   int res = s2.top();
    //   s2.pop();
    //   return res;
    // }
    
    /** Get the front element. */
    // 保持最早进来的在输出栈的top
    // int peek() {
    //   if(s2.empty())
    //     inToOut();
    //   return s2.top();
    // }
    
    /** Returns whether the queue is empty. */
    // bool empty() {
    //   return s1.empty() && s2.empty();
    // }

    // void push(int x) {
    //     stack<int> tmp_stack;
    //     while(!_data.empty()) {
    //         tmp_stack.push(_data.top());
    //         _data.pop();
    //     }
    //     tmp_stack.push(x);
    //     while(!tmp_stack.empty()) {
    //         _data.push(tmp_stack.top());
    //         tmp_stack.pop();
    //     }
    // }

    // int pop() {
    //     int x = _data.top();
    //     _data.pop();
    //     return x;
    // }

    // int peek() {
    //     return _data.top();
    // }

    // bool empty() {
    //     return _data.empty();
    // }

    void push(int x)
    {
        stIn.push(x);
    }

    int pop()
    {
        if(stOut.empty())
        {
            while(!stIn.empty())
            {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int res = stOut.top();
        stOut.pop();
        return res;
    }

    int peek()
    {
        int res = pop();
        stOut.push(res);
        return res;
    }

    bool empty()
    {
        return stIn.empty() && stOut.empty();
    }

private:
    stack<int> stIn;
    stack<int> stOut;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

