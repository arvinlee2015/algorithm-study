class Solution{
public:
  int lengthOfLongestSubstring(string s){
    vector<int> search(256, -1);
    int max_len = 0;
    int start = -1;
    for(int i = 0; i != s.length(); i++){
      if (search[s[i]] > start)
        start = search[s[i]];
      search[s[i]] = i;
      max_len = max(max_len, i - start);
    }
    return max_len;
  }
};
