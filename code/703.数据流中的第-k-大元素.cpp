/*
 * @lc app=leetcode.cn id=703 lang=cpp
 *
 * [703] 数据流中的第 K 大元素
 */

// @lc code=start
class KthLargest {
public:

    typedef pair<int,int> PII;
    set<PII> s;   // 不允许重复，那么就整两个元素，让它永远不可能重复
    int kn;
    KthLargest(int k, vector<int>& nums) {
        kn = k;
        for(int n:nums) {
            if(s.size()<k)
                s.insert(PII(n,rand()));
            else if(s.begin()->first < n) {
                s.erase(s.begin());
                s.insert(PII(n,rand()));
            }
        }
    }
    
    int add(int val) {
        if(s.size() + 1 < kn) return NULL;
        else if(s.size() + 1 == kn) s.insert(PII(val,rand()));
        else if(s.begin()->first < val) {
            s.erase(s.begin());
            s.insert(PII(val,rand()));
        }
        return s.begin()->first;
    }
    
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

