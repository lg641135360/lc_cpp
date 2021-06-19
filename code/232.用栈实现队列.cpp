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
    void push(int x) {
      s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
      // 当输出栈空时，搬运
      if(s2.empty())
        inToOut();
      int res = s2.top();
      s2.pop();
      return res;
    }
    
    /** Get the front element. */
    // 保持最早进来的在输出栈的top
    int peek() {
      if(s2.empty())
        inToOut();
      return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
      return s1.empty() && s2.empty();
    }

private:
  stack<int> s1;
  stack<int> s2;
  // 将输入搬到输出
  void inToOut(){
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
  }
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

