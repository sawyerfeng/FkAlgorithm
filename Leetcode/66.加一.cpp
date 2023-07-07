/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode.cn/problems/plus-one/description/
 *
 * algorithms
 * Easy (45.34%)
 * Likes:    1221
 * Dislikes: 0
 * Total Accepted:    621.6K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = [1,2,3]
 * 输出：[1,2,4]
 * 解释：输入数组表示数字 123。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = [4,3,2,1]
 * 输出：[4,3,2,2]
 * 解释：输入数组表示数字 4321。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = [0]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int begin=digits.size();
        int tmp=begin-1;
        for(int i=begin-1;i>=0;i--){
            if(digits[i]==9){
                tmp--;
                digits[i]=0;
                std::cout<<"1:"<<tmp<<endl;
            }else
               { break;}
        }
        std::cout<<"2:"<<tmp<<endl;
        if(tmp==-1){
            vector<int> ans(begin + 1);
            cout<<ans[1]<<endl;
            ans[0] = 1;
            return ans;
        }
        digits[tmp]++;
        return digits;
    }
};
// @lc code=end

