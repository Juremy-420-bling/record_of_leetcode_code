/*
*任务：基本的二分查找，找到了返回下标，没找到返回-1
*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1; //定义两个int型变量，标记左右的范围
        while (left <= right) { //while循环判断的条件是左边的值小于等于右边的值
            int mid = left + (right - left) / 2; //求中间的值
            if(nums[mid] == target) {
                 return mid; //如果中间值是目标值，则返回该中间值，这个mid就是中间值
            } else if(nums[mid] > target) {
                right = mid - 1; //如果中间值大于目标值，将中间值的前一位更新到right中
            } else {
                left = mid + 1; //如果中间值小于目标值，将中间值的后一位left中
            }
        }
        return -1; //没有找到target，返回-1
    }
};