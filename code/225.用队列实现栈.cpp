/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack
{
public:
    /** Initialize your data structure here. */
    // MyStack() {

    // }

    /** Push element x onto stack. */
    // 每次往第一个插入
    // void push(int x) {
    //   q.push(x);
    //   // 进行n-1次插尾操作(把第一个插到最后)
    //   for(int i = 1;i<q.size();i++){
    //     q.push(q.front());
    //     q.pop();
    //   }
    // }

    /** Removes the element on top of the stack and returns that element. */
    // int pop() {
    //   int res = q.front();
    //   q.pop();
    //   return res;
    // }

    /** Get the top element. */
    // int top() {
    //   return q.front();
    // }

    /** Returns whether the stack is empty. */
    // bool empty() {
    //   return q.empty();
    // }

    //     void push(int x) {
    //         queue<int> tmp_q;
    //         tmp_q.push(x);
    //         while(!q.empty()) {
    //             tmp_q.push(q.front());
    //             q.pop();
    //         }
    //         while(!tmp_q.empty()) {
    //             q.push(tmp_q.front());
    //             tmp_q.pop();
    //         }
    //     }

    //     int pop() {
    //         int x = q.front();
    //         q.pop();
    //         return x;
    //     }

    //     int top() {
    //         return q.front();
    //     }

    //     bool empty() {
    //         return q.empty();
    //     }

    // private:
    //     queue<int> q;
    //     void push(int x)
    //     {
    //         que1.push(x);
    //     }

    //     int pop()
    //     {
    //         int size = que1.size();
    //         size--;
    //         while (size--)
    //         {
    //             que2.push(que1.front());
    //             que1.pop();
    //         }

    //         int res = que1.front();
    //         que1.pop();
    //         que1 = que2;
    //         while (!que2.empty())
    //             que2.pop();
    //         return res;
    //     }

    //     int top()
    //     {
    //         return que1.back();
    //     }

    //     bool empty()
    //     {
    //         return que1.empty();
    //     }

    // private:
    //     queue<int> que1;
    //     queue<int> que2;

    void push(int x)
    {
        que.push(x);
    }

    int pop()
    {
        int size = que.size();
        size--;
        while (size--)
        {
            que.push(que.front());
            que.pop();
        }
        int res = que.front();
        que.pop();
        return res;
    }

    int top()
    {
        return que.back();
    }

    bool empty()
    {
        return que.empty();
    }

private:
    queue<int> que;
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
