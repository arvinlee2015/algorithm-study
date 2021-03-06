/*
知识点：
map、vector

思想:
总结：读完题首先想到的就是两层遍历法，但是显然时间复杂度太高，是O(N^2)，不符合要求，
于是就应该想如何降低复杂度，首先应该想将逐个比较转变为直接查找，即首先计算出 target与当前元素的差，
然后在序列中寻找这个差值，这样首先就把问题简化了，而寻找的过程可以先对序列进行快排，然后二分查找，这样整体的复杂度就降低为 O(N*logN) 了；
查找最快的方法是利用一个 map容器存储每个元素的索引，这样取得某个特定元素的索引只需要常数时间即可完成，这样就更快了，最多只需遍历一次序列，
将元素及其索引加入map中，在遍历的过程中进行对应差值的查找，如果找到了就结束遍历，这样时间复杂度最多为 O(N）
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            int n = target - nums[i];
            if(hash.find(n) != hash.end()){
                result.push_back(hash[n] + 1);
                result.push_back(i + 1);
                return result;
            }
            hash.insert(pair<int,int>(nums[i], i));
            //hash[nums[i]] = i;
        }
        return result;
    }
};
