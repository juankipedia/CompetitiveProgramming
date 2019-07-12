#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);


int main(){
    string s[4];
    vector<int> v[4];
    for(int i = 1;i<=3;i++){
        cin>>s[i];
        if(s[i][1]=='s'){
            v[1].push_back(s[i][0]-'0');
        }
        if(s[i][1]=='m'){
            v[2].push_back(s[i][0]-'0');
        }
        if(s[i][1]=='p'){
            v[3].push_back(s[i][0]-'0');
        }
    }
    int ans = 2;
    for(int i = 1;i<=3 ;i++){
        int len = v[i].size();
        sort(v[i].begin(),v[i].end());
        if(len==1) continue;
        if(len ==2){
            if(v[i][0]==v[i][1]||v[i][0]==v[i][1]-1||v[i][0]==v[i][1]-2) ans = 1;
        }
        if(len == 3){
            if((v[i][0]==v[i][1]&&v[i][2]==v[i][1])||(v[i][0]==v[i][1]-1&&v[i][1]==v[i][2]-1)) ans  = 0;
            else if((v[i][0]==v[i][1]||v[i][2]==v[i][1])||(v[i][0]==v[i][1]-1||v[i][1]==v[i][2]-1)||v[i][0]==v[i][1]-2||v[i][1]==v[i][2]-2){
                ans = 1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}