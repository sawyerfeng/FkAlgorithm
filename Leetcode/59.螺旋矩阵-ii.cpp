// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem59.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode.cn/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (72.72%)
 * Likes:    1084
 * Dislikes: 0
 * Total Accepted:    331.2K
 * Total Submissions: 455.9K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int offset = 1;
        int count = 1;
        int startx = 0;
        int starty = 0;
        int loop =n/2;
        vector<vector<int>> nums(n,vector<int>(n,0));
        while(loop --){
            int i = startx;
            int j = starty;
            for(j = starty; j < n - offset ; j++) nums[i][j] = count++;
            for(i = startx; i < n - offset ; i++) nums[i][j] = count++;
            for(; j > starty ; j --) nums[i][j] = count++;
            for(; i > startx ; i --) nums[i][j] = count++;
            startx++;
            starty++;
            offset++;  
        }
        if(n%2){
            nums[n/2][n/2] = count;
        }
        return nums;

    }
};
// @lc code=end

