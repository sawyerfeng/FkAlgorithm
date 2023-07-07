/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode.cn/problems/add-binary/description/
 *
 * algorithms
 * Easy (53.04%)
 * Likes:    1013
 * Dislikes: 0
 * Total Accepted:    318.9K
 * Total Submissions: 601.4K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入:a = "11", b = "1"
 * 输出："100"
 * 
 * 示例 2：
 * 
 * 
 * 输入：a = "1010", b = "1011"
 * 输出："10101"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= a.length, b.length <= 10^4
 * a 和 b 仅由字符 '0' 或 '1' 组成
 * 字符串如果不是 "0" ，就不含前导零
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int alen=a.size();
        int blen=b.size();
        while(alen<blen){
            a='0'+a;
            alen++;
        }
        while(blen<alen){
            b='0'+b;
            blen++;
        }
        for(int i=a.size()-1;i>0;--i){
            a[i]=a[i]+b[i]-'0';
            if(a[i]>='2'){
                a[i]=(a[i]-'0')%2+'0';
                a[i-1]=a[i-1]+1;
            }   
        }
        a[0]=a[0]-'0'+b[0];
        if(a[0]>='2'){
            a[0]=(a[0]-'0')%2+'0';
            a='1'+a;
        }
        return a;


    }
};
// @lc code=end

