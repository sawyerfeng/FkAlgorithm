/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 *
 * https://leetcode.cn/problems/squares-of-a-sorted-array/description/
 *
 * algorithms
 * Easy (67.96%)
 * Likes:    827
 * Dislikes: 0
 * Total Accepted:    548.1K
 * Total Submissions: 806.5K
 * Testcase Example:  '[-4,-1,0,3,10]'
 *
 * 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-4,-1,0,3,10]
 * 输出：[0,1,9,16,100]
 * 解释：平方后，数组变为 [16,1,0,9,100]
 * 排序后，数组变为 [0,1,9,16,100]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [-7,-3,2,3,11]
 * 输出：[4,9,9,49,121]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 10^4
 * -10^4 
 * nums 已按 非递减顺序 排序
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 请你设计时间复杂度为 O(n) 的算法解决本问题
 * 
 * 
 * 
 * 
 * 解法：
 * 双指针，左右为绝对值最大的，比较两者，选出最大，存入新数组
 * 
 */
// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(),0);
        int front = 0, back = nums.size()-1;
        int k = back;
        while(front <= back){
            if(nums[front] * nums[front] < nums[back] * nums[back] ){
                result[k--]=(nums[back] * nums[back]);
                back --;
            }else{
                result[k--]=(nums[front] * nums[front]);
                front ++;
            }
        }
        return result;


    }
};
// @lc code=end

