/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start

class MyQueue
{ //单调队列（从大到小）
public:
    deque<int> que; // 使用deque来实现单调队列
    // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
    // 同时pop之前判断队列当前是否为空。
    void pop(int value)
    {
        if (!que.empty() && value == que.front())
        {
            que.pop_front();
        }
    }
    // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
    // 这样就保持了队列里的数值是单调从大到小的了。
    void push(int value)
    {
        while (!que.empty() && value > que.back())
        {
            que.pop_back();
        }
        que.push_back(value);
    }
    // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
    int front()
    {
        return que.front();
    }
};

class Solution
{
public:
    // 暴力破解法，原来数组太长时 超时
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> window_max(nums.size()-k+1,0);
    //     for(int i=0;i<window_max.size();++i)
    //         window_max[i] = max_of_windows(nums,i,i+k);
    //     return window_max;
    // }

    // // 左闭右开
    // int max_of_windows(vector<int> &nums,int begin,int end) {
    //     int max_ = nums[begin];
    //     for(int i=begin+1;i<end;++i)
    //         max_ = max(max_,nums[i]);
    //     return max_;
    // }

    // template<typename T>
    // class custom_priority_queue : public std::priority_queue<T, std::vector<T>>
    // {
    // public:
    //     bool remove(const T& value) {
    //         auto it = std::find(this->c.begin(), this->c.end(), value);
    //         if (it != this->c.end()) {
    //             this->c.erase(it);
    //             std::make_heap(this->c.begin(), this->c.end(), this->comp);
    //             return true;
    //         }
    //         else {
    //             return false;
    //         }
    //     }
    // };

    // 采用提示的滑动窗口和堆解决
    // 堆 -> 小顶/大顶，这里要求大小为k的窗口中最大值
    // 采用大小为k的大顶堆，得到一个值后，搜索删除第一个位置的值
    // 依然超时
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     custom_priority_queue<int> q;
    //     vector<int> window_max;
    //     for(int i=0;i<nums.size();++i) {
    //         // 当堆中元素少于k个，直接入堆
    //         if(q.size() < k) {
    //             q.push(nums[i]);
    //         }
    //         // 大顶堆中元素已经==k，
    //         else{
    //             window_max.push_back(q.top());
    //             q.remove(nums[i-k]);
    //             i--;
    //         }
    //     }
    //     window_max.push_back(q.top());
    //     return window_max;
    // }

    // 优化第二种做法，不是每个时候都需要删除（时复太高）
    // 只有当大顶 不在窗口内时候，才需要删除该大顶，保证其一直处于窗口内
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     priority_queue<pair<int,int>> window;
    //     vector<int> res;
    //     for(int i=0,n=nums.size();i<n;i++) {
    //         // 当窗口不空且最大值不在窗口内，循环删除大顶
    //         while(!window.empty() && window.top().second <= i-k)
    //             window.pop();
    //         window.push({nums[i],i});
    //         // 添加时机很重要
    //         if(i>=k-1)
    //             res.push_back(window.top().first);
    //     }
    //     return res;
    // }

    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MyQueue que;
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            que.push(nums[i]);
        }
        res.push_back(que.front());
        for (int i = k; i < nums.size(); i++)
        {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
};

// @lc code=end
