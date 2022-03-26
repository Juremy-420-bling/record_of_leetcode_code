/*
*   任务：在数组找到满足和为target的两个数，然后输出这两个数在数组中的顺序(两头夹逼法)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int front = 0, end = numbers.size() - 1;
        while(front <= end) {
            int frontNum = numbers[front]; 
            int division = target - frontNum;//每次循环开始，确定当前front的值要找的end的值应该是多少
            while(numbers[end] > division){//while就是来确定有多少的
                end--;
            }
            if(numbers[end] == division) //判断是否相等，是则返回，否则将front++
                return {front + 1, end + 1};
            front++;
        }
        return {0};
    }
};