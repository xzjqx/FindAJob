class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        sort(numbers.begin(), numbers.end());
        int cnt = 1, m = 1, ans = numbers[0];
        for(int i = 1; i < numbers.size(); i ++) {
            if(numbers[i] == numbers[i-1]) {
                cnt ++;
            } else {
                if(m < cnt) {
                    m = cnt;
                    ans = numbers[i-1];
                }
                cnt = 1;
            }
        }
        if(m > numbers.size() / 2) return ans;
        else return 0;
    }
};

class Solution1 {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        // 因为用到了sort，时间复杂度O(NlogN)，并非最优
        if(numbers.empty()) return 0;
         
        sort(numbers.begin(),numbers.end()); // 排序，取数组中间那个数
        int middle = numbers[numbers.size()/2];
         
        int count=0; // 出现次数
        for(int i=0;i<numbers.size();++i)
        {
            if(numbers[i]==middle) ++count;
        }
         
        return (count>numbers.size()/2) ? middle :  0;
    }
};

class Solution2 {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
        if(numbers.empty()) return 0;
         
        // 遍历每个元素，并记录次数；若与前一个元素相同，则次数加1，否则次数减1
        int result = numbers[0];
        int times = 1; // 次数
         
        for(int i=1;i<numbers.size();++i)
        {
            if(times == 0)
            {
                // 更新result的值为当前元素，并置次数为1
                result = numbers[i];
                times = 1;
            }
            else if(numbers[i] == result)
            {
                ++times; // 相同则加1
            }
            else
            {
                --times; // 不同则减1               
            }
        }
         
        // 判断result是否符合条件，即出现次数大于数组长度的一半
        times = 0;
        for(int i=0;i<numbers.size();++i)
        {
            if(numbers[i] == result) ++times;
        }
         
        return (times > numbers.size()/2) ? result : 0;
    }
};