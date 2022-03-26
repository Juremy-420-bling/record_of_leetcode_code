/*
*任务：将所有的数进行平方然后，按顺序放到数组中(两头夹逼法)
*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        vector<int> res;
        vector<int>::iterator iterFront = nums.begin();
        vector<int>::iterator iterEnd = nums.end();
        iterEnd--; //指向最后一个元素
        while(iterFront <= iterEnd) {
            int front = (*iterFront) * (*iterFront); //把最前的数做平方
            int end = (*iterEnd) * (*iterEnd);//把最后的数做平方
            if(front <= end) { //先把所有的数由大到小排列
                result.push_back(end); //把大的先放入
                iterEnd--;
            } else {
                result.push_back(front);//把大的先放入
                iterFront++;
            }
        }
        vector<int>::iterator iter = result.end();
        iter--;
        for(;iter>=result.begin(); iter--){ //然后将数组翻过来
            res.push_back(*iter);
        }
        return res;
    }
};