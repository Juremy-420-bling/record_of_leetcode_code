// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

/*
*任务：输入n代表有多少个版本，需要我们找第一个出现错误的版本
*/
class Solution {
public:
    int firstBadVersion(int n) {
        int mid = n / 2;
        int low = 1;
        while(low <= n){
            if (isBadVersion(mid))
                if (!isBadVersion(mid - 1))
                    return mid;
                else {
                    n = mid - 1;
                }
            else {
                if (isBadVersion(mid + 1))
                    return mid + 1;
                else {
                    low = mid + 1;
                }
            }
            mid = low + (n - low) / 2;
        }
        return n;
    }
};