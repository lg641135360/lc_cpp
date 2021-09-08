/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
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
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> window;
        vector<int> res;
        for(int i=0,n=nums.size();i<n;i++) {
            // 当窗口不空且最大值不在窗口内，循环删除大顶
            while(!window.empty() && window.top().second <= i-k)
                window.pop();
            window.push({nums[i],i});
            // 添加时机很重要
            if(i>=k-1)
                res.push_back(window.top().first);
        }
        return res;
    }

};
// @lc code=end

