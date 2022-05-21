/**
 *
 * LIS, longest incriasing subsequence.
 * NOTE: 
 *  if the sequence is not strictly grater change line 19 for using upper_bound instead of
 *  lower_bound and chance line 30 for using s[i] <= s[pos] instead of s[i] < s[pos].
 *  
 *  This problem could also be solved using a segment tree dp.
 *  For each element in s, find max(dp[s[i]], dp[s[i] - 1])
 * 
 * */

const int MAXN = 30000;
int len, n;
int s[MAXN], lis[MAXN];

void LIS(){
    len = 0;
    vector<int> l;
    int lis_len[MAXN], pos;
    for(int i = 0; i < n; i++){
        int j = lower_bound(l.begin(), l.end(), s[i]) - l.begin();
        if(j == l.size()) l.push_back(s[i]);
        else l[j] = s[i];
        lis_len[i] = j + 1;
        if(lis_len[i] > len){
            len = lis_len[i];
            pos = i;
        }
    }
    lis[len - 1] = s[pos];
    for(int i = pos - 1, j = len - 2; i >= 0; i--){
        if(s[i] < s[pos] && lis_len[i] == lis_len[pos] - 1){
            pos = i;
            lis[j] = s[i];
            j--;
        }
    }
}