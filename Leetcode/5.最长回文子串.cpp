/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode.cn/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (37.43%)
 * Likes:    6293
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 3.6M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {

        int maxlen=1;
        int begin=0;
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        if(n<2){
            return s;
        }
        for (int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int len=2;len<=n;len++){
            for(int left=0;left<n;left++){
                int right=len+left-1;
                if(right>=n){
                    break;
                }
                if(s[left]!=s[right]){
                    dp[left][right]=false;
                }else {
                    if(right-left<3){
                        dp[left][right]=true;
                    }else{
                        dp[left][right]=dp[left+1][right-1];
                }
                }
                if(dp[left][right]&&right-left+1>maxlen){
                    maxlen=right-left+1;
                    begin=left; 
            }

            }
        }
        return s.substr(begin,maxlen);
        

    }
};
// @lc code=end

