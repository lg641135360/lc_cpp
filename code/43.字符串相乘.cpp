/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
    // 模拟计算过程
    string multiply(string num1, string num2) {
        // base case
        if(num1=="0"||num2=="0")
            return "0";

        vector<string> res_list;
        string res = "";
        for(int i=num2.size()-1;i>=0;--i) {
            int curr = num2[i] - '0';
            string res_i = "";
            string num1_ = num1;
            int increase = 0;
            while(!num1_.empty()) {
                int last = num1_.back() - '0';
                num1_.pop_back();
                int tmp = curr * last + increase;
                if(tmp / 10) {
                    increase = tmp/10;
                    res_i += to_string(tmp%10);
                }
                else {
                    increase = 0;
                    res_i +=to_string(tmp);
                }
            }
            if(increase) res_i += to_string(increase);
            num1_ = num1;
            reverse(res_i.begin(),res_i.end());
            for(int p=num2.size()-1-i;p>0;--p)
                res_i += '0';
            res_list.push_back(res_i);
        }
        sum_(res_list,res);
        
        for(int i=0;i<res.size();++i) 
            if(res[i] != '0') 
                return res.substr(i);
            
        return res;
    }

    void sum_(vector<string> &res_list,string &res) {
        if(res_list.size()==1) {
            res = res_list[0];
            return;
        }
        for(int i=0;i<res_list.size();++i) 
            sum_l(res_list[i],res);
    }

    void sum_l(string s1,string &res) {
        if(res == "") {
            res += s1;
            return ;
        }
    
        int increase = 0;
        int count = 0;
        string s2 = res;
        res = "";
        while(!s1.empty()&&!s2.empty()) {
            int last1 = s1.back() - '0';
            int last2 = s2.back() - '0';
            s1.pop_back();
            s2.pop_back();
            count ++;
            int tmp = last1+last2+increase;
            if(tmp/10) {
                increase = 1;
                res +=to_string(tmp%10);
            }
            else {
                increase = 0;
                res +=to_string(tmp);
            }
        }
        if(!s1.empty()) {
            if(increase)
                plus1(s1);
            
            increase =0;
            reverse(s1.begin(),s1.end());
            res += s1;
        }
        

        if(!s2.empty())  {
            if(increase)
                plus1(s2);
            increase = 0;
            reverse(s2.begin(),s2.end());
            res += s2;
        }
        
        if(increase) 
            res += to_string(increase);

        reverse(res.begin(),res.end());
        // for(int i=0;i<res.size();++i)
        //     if(res[i] != '0')
        //         res.substr(i);
    }

    void plus1(string &s) {
        vector<int> res;
        for(int s1:s)
            res.push_back(s1 - '0');
        res = plusOne(res);
        string res_s="";
        for(int i=0;i<res.size();++i)
            res_s += to_string(res[i]);
        s = res_s;
    }

    vector<int> plusOne(vector<int>& digits) {

       for(int i = digits.size()-1; i>=0; i--){
           digits[i]++;
           digits[i] %=10;
           if(digits[i] != 0) return digits;
       } 
        // 如果到了这一行都没有返回，那么说明每一列都进位9999
        digits.insert(digits.begin(),1);
        return digits;
    }

};
// @lc code=end

