/*
*任务：将数组中所有的零放到右边，然后左边的数保持原有顺序排列(同步双指针法)
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      /*  int len = nums.size();
        int i = 0;
        int sumOfZero = 0;
        int currentSum = 0;
        while(nums[i] != 0) {
            i++; //这一步是为了找到第一个0
        }
        do { //开始执行的时候，i的位置应该是0
            currentSum = 1;
            while(i < len - 1 & nums[i+1] == 0) {//解决连0情况
                currentSum++;//记录此时有多少个连零
                i++; 
            }
            int j = 1;
            sumOfZero += currentSum; //记录已经跨过多少个零
            for(; nums[i+j] != 0 && i+j < len-1; j++){ //这一步是为了放开来跑.完全遍历一遍
                nums[i+j-sumOfZero] = nums[i+j];
            } 
            i += j;
        }while(i < len-1);
        //此时的i的位置可能是0.也可能不是0
        if(nums[len-1] == 0)
            sumOfZero++;
        for(int j=0; j<=len-1; j++)
            nums[len-sumOfZero+j] = 0;
      */
        // vector<int> zero;
        // int len = nums.size();
        // int sumOfZero = 0;
        // int j = 0;
        // int move = 0;
        // for(int i=0; i<=len; i++){//这里是为了找出nums中所有的0，并且把他们的下标存在zero中，sumOfZero记录有多少个0
        //     if(nums[i] == 0){
        //         zero.push_back(i);
        //         sumOfZero++;
        //     }
        // }
        // for(int i=0; i<=len;){ //第二次遍历
        //     int k=0;
        //     if(i == zero[j] & i+1 != zero[j+1]){ //判断此时的i是否是零的下标，以及下一个下标是不是零
        //         j++;
        //         move++; //每位要移动的个数
        //         k=1;
        //     }else{
        //         for(; zero[j+k] == i+k; k++){
        //         }
        //         j += k;
        //         move += k;
        //     }
        //     if(i + )
        //     for(int m=0; m != zero[j]; m++)//一次局部的移位
        //         nums[i+m] = nums[i+m+move];
        //     i += k;
        //}
        int n = nums.size(), left = 0, right = 0; //这个做法妙在避免数组只有一个零的情况，而且把数组每次处理完的状态都规整为已处理完序列，待处理序列，以及中间的0
        while (right < n) { //在算法进行过程中，左边指针的左边是已经处理好的数据，左右指针之间是零，右指针的右边是待处理的数据
            if (nums[right]) { //右指针扫到零，就不发生交换，左指针不动，右指针向右移一位
                swap(nums[left], nums[right]);//右指针扫到非零常数，则左指针与右指针的值交换，左指针实际上一直指的是零
                left++;
            }
            right++;
        }
    }
};