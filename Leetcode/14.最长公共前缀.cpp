/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int length=strs[0].length(); 
        int size=strs.size();
        if(size==0) 
        return "";
        for(int i=0;i<length;i++){
            for(int j=1;j<size;j++){
                if(strs[0][i]!=strs[j][i]||i==strs[j].size()){
                    return strs[j].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};
// @lc code=end

