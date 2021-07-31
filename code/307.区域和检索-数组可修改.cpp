/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) {
        if(nums.size() == 0) return ;
        int n=nums.size() * 4;
        for(int i=0;i<n;++i)
            _value.push_back(0);
        build_segment_tree(_value,nums,0,0,nums.size()-1);
        _right_end = nums.size() - 1;
    }
    
    void update(int i, int val) {
        update_segment_tree(_value,0,0,_right_end,i,val);
    }
    
    int sumRange(int i, int j) {
        return sum_range_segment_tree(_value,0,0,_right_end,i,j);
    }
private:
    vector<int> _value;
    int _right_end;

    void build_segment_tree(vector<int> &value,vector<int> &nums,int pos,int left,int right) {
        if(left == right) {
            value[pos] = nums[left];
            return;
        }
        int mid = (left+right) /2;
        build_segment_tree(value,nums,pos*2+1,left,mid);
        build_segment_tree(value,nums,pos*2+2,mid+1,right);
        value[pos] = value[pos*2+1] + value[pos*2+2];
    }

    int sum_range_segment_tree(vector<int> &value,int pos,int left,int right,int qleft,int qright) {
        if(qleft>right || qright<left)
            return 0;
        if(qleft<=left&&qright>=right)
            return value[pos];
        int mid = (left+right)/2;
        return sum_range_segment_tree(value,pos*2+1,left,mid,qleft,qright) + sum_range_segment_tree(value,pos*2+2,mid+1,right,qleft,qright);
    }

    void update_segment_tree(vector<int> &value,int pos,int left,int right,int index,int new_value) {
        if(left==right&&left==index) {
            value[pos] = new_value;
            return;
        }
        int mid=(left+right)/2;
        if(index<=mid) 
            update_segment_tree(value,pos*2+1,left,mid,index,new_value);
        else 
            update_segment_tree(value,pos*2+2,mid+1,right,index,new_value);
        value[pos] = value[pos*2+1]+value[pos*2+2];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

