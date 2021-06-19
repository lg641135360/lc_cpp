/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
    
    /** Initialize your data structure here. */
    // MyStack() {
      
    // }
    
    /** Push element x onto stack. */
    // 每次往第一个插入
    void push(int x) {
      q.push(x);
      // 进行n-1次插尾操作(把第一个插到最后)
      for(int i = 1;i<q.size();i++){
        q.push(q.front());
        q.pop();
      }

    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
      int res = q.front();
      q.pop();
      return res;
    }
    
    /** Get the top element. */
    int top() {
      return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
      return q.empty();
    }
private:
    queue<int> q; 
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

