/**
 * 
 * MANACHER.
 * 
 * Given string s with length n. Find all the pairs (i, j) such that substring s[i … j] 
 * is a palindrome. For each position i = 0 … n − 1 we'll find the values d1[i] and d2[i], 
 * denoting the number of palindromes accordingly with odd and even lengths respectively with 
 * centers in the position i. For even length palindromes they have 2 center for example:
 *     "baab", has two centers (positions 1 and 2).
 * d2[] will use right most center as the center of the palindrome, in the example above d2[]
 * will use position 2.
 * 
 * time complexity: O(n).
 * 
 **/

void manacher(string &s, vector<int> &d1, vector<int> &d2){
    int n = s.size();
    d1.assign(n, 0);
    for(int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while(0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
        d1[i] = k--;
        if(i + k > r){
            l = i - k;
            r = i + k;
        }
    }
    d2.assign(n, 0);
    for(int i = 0, l = 0, r = -1; i < n; i++){
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while(0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
        d2[i] = k--;
        if(i + k > r){
            l = i - k - 1;
            r = i + k ;
        }
    }
}