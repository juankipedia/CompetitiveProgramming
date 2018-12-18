#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string str, unsigned int &n){
    int l = 0; 
    int h = n - 1; 
    while (h > l) if (str[l++] != str[h--]) return false; 
    return true;
} 

bool are_all_same(string str, unsigned int &n){
    char c = str[0];
    for(unsigned int i = 1; i < n; i++)
        if(str[i] != c)
            return false;
    return true;
} 

int main() {
    unsigned int t;
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        unsigned int n = s.length();
        if(not is_palindrome(s, n))
            cout << s << endl;
        else if(n == 1)
            cout << -1 << endl;
        else if(are_all_same(s, n))
            cout << -1 << endl;    
        else{
            do{
                char c = s[n - 1];
                s = s.substr(0, n - 1);
                s.insert(n / 2, 1, c);
            }while(is_palindrome(s, n));
            cout << s << endl;
        }   
    }
    return 0;
}