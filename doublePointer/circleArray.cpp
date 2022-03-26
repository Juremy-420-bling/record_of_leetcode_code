/*
*给定一个k，将数组向右挪动k位(双指针的简单运用)
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>::iterator iter = nums.end();
        vector<int>::iterator iter1 = nums.begin();
        vector<int> mid; //这里相当于多了一个数组
        //iter--;
        k %= nums.size();
        iter -= k;
        cout << '[';
        for(int i=0; i < k; i++) {//负责需要右移至前面的迭代器
            mid.push_back(*iter);
            iter++;
        }
        for(int i=0; i<nums.size() - k; i++) {//负责需要往后挪的迭代器
            mid.push_back(*iter1);
            *iter1++;
        }
        nums.assign(mid.begin(), mid.end()); //assign的输入是另一个数组的迭代器
    }
};