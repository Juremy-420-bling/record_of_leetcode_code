/* 任务：利用二分查找升序数组中是否存在目标值。若存在，返回其下标，若不存在，返回其插入后所在下标
*
*/
class Solution{
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1; //初始化计算中需要用到的变量
        int mid = high / 2;
        if(nums[high] < target) //这两行是为了处理极端情况
            return high + 1;
        if(nums[0] > target)
            return 0;
        while(low <= high) { //循环的条件是，左边的指针不能越过右边的指针
            if(nums[mid] == target) //判断是否找到target值
                return mid;
            else if(num[mid] < target) {
                if(num[mid+1] > target) { //小于target值时，看看后一位是否大于target，是的话，就找到了target插入的点
                    return mid + 1;
                } else {
                    low = mid + 1; //如果不是，说明还要继续寻找，更新左指针
                }
            } else {
                if(nums[mid-1] < target) { //大于target值时，看看前一位是否小于target，是的话，就找到了target插入的点
                    return mid;
                } else {
                    high = mid - 1; //如果不是，说明还要继续寻找，更新右指针
                }
            }
            mid = low + (high - low) / 2;
        }
    }
};