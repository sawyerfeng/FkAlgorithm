/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        map<char,int> rom2int;
        int sum=0;
        rom2int.insert(pair<char,int>('I',1));
        rom2int.insert(pair<char,int>('V',5));
        rom2int.insert(pair<char,int>('X',10));
        rom2int.insert(pair<char,int>('L',50));
        rom2int.insert(pair<char,int>('C',100));
        rom2int.insert(pair<char,int>('D',500));
        rom2int.insert(pair<char,int>('M',1000));
        for(int i=0;i<s.length();i++){
            if(i<s.length()-1&&rom2int[s[i]]<rom2int[s[i+1]]){
                sum-=rom2int[s[i]]; 
            }else{
                sum+=rom2int[s[i]];
            }
           
        }
        return sum;

    }
};
// @lc code=end

