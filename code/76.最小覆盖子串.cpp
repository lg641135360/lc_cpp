/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    // s母串，t模式串
    string minWindow(string s, string t) {
        // t中每个字符缺失的数量
        vector<int> chars(128,0);
        // 每个字符是否在t中存在
        vector<bool> flag(128,false);
        
        // 1.统计t中字符情况
        for(int i = 0;i<t.size();i++){
            // 每个字符都是用ascii码表示（128个不同的数字）但这里是字母，其实是冗余了
            flag[t[i]] = true;
            ++chars[t[i]];
        }
        // 移动滑动窗口，不断更改统计数据
        int cnt = 0, l = 0, min_l = 0, min_size = s.size()+1;
        for (int r = 0; r < s.size(); ++r) {  // 注意r窗口右边界
            if(flag[s[r]]) // s中有t中需要的
                if(--chars[s[r]] >= 0) // 取到
                    ++cnt; // 计数
            // 循环结束后才会执行下面代码，此时滑动窗口中应该已经有了t中所有字母
            // 尝试将l右移，在不影响结果的情况下获得最短子字符串
            while(cnt==t.size()){ // 在获取到所有t中字符后才执行
                // 更新
                if(r-l +1<min_size){
                    min_l = l;
                    min_size = r - l + 1;
                }
                // 当前左边界是所需要的，并且缺失，就减小cnt，让其继续寻找
                if(flag[s[l]] && ++chars[s[l]] > 0) {
                    --cnt; // 减去之后，重新执行上面代码，继续收集t中字符
                }
                // 右移左边界l，一般是不存在于模式串中的
                ++l;
            }
        }
        // 找不到（r-l+1>s.size()）
        return min_size > s.size()?"":s.substr(min_l, min_size);
    }
};
// @lc code=end

