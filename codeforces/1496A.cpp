# include <bits/stdc++.h>
using namespace std;



int main(){
    int T;
    int n;
    int k;
    
    cin >> T;
    while(T--){
        string str;
        cin >> n >> k >> str;
        set<int> sss;
        bool AC = false;
        int i = 0, j = n - 1;
        while(i < j){
            if(str[i] != str[j]) break;
            else{ i+=1; j-=1;}
        }
        if(i == j){
            if(i >= k) AC = true;
            else AC = false;
        }
        else if(i > j){
            if(i - 1 >= k) AC = true;
            else AC = false;
        }
        else{
            if(i >= k) AC = true;
            else AC = false;
        }

        if(!AC) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }
    return 0;
}