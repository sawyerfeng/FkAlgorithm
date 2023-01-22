/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode.cn/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.54%)
 * Likes:    2848
 * Dislikes: 0
 * Total Accepted:    581.5K
 * Total Submissions: 750K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 8
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        dfs("",0,n);
        return ans;




    }
    void dfs(string s,int exit,int left){
        if(exit==0&&left==0) ans.push_back(s);
        if(exit==0&&left!=0) dfs(s+"(",exit+1,left-1);
        if(exit!=0&&left==0) dfs(s+")",exit-1,left);
        if(exit!=0&&left!=0){
            dfs(s+"(",exit+1,left-1);
            dfs(s+")",exit-1,left);
        }
        

    }
};
// @lc code=end

