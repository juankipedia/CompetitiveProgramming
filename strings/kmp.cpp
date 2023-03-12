/**
 *  KMP.
 * You are given a string s of length n. The prefix function for this string is defined as an array lps of length n, where 
 * lps[i] is the length of the longest proper prefix of the substring s[0...i] which is also a suffix of this substring. 
 * A proper prefix of a string is a prefix that is not equal to the string itself. By definition, lps[0] = 0.
 * Time complexity: O(n)
 **/

string txt, p;
int lps[1000000];

void LPS(){
    memset(lps, 0, sizeof(lps));
    int n = p.size(), j = 1, i = 0;
    while(j < n){
        if(p[j] == p[i]) lps[j++] = ++i;
        else if(i == 0) lps[j++] = 0;
        else i = lps[i - 1];
    }
}

vector<int> find_pattern(){
    LPS();
    vector<int> ans;
    int i = 0, j = 0;
    while(i < txt.size()){
        if(txt[i] == p[j]){j++; i++;}
        if(j == p.size()){
            ans.push_back(i - j + 1);
            j = lps[j - 1];
        }
        else if(i < txt.size() && p[j] != txt[i]){
            if(j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return ans;
}
