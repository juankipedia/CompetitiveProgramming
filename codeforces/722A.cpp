#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int format;
string time_;
int main(){
    cin >> format;
    cin >> time_;

    if(format == 12){
        if(time_[0] - '0' > 1){
            if(time_[1] - '0' > 2) time_[0] = '0';
            else time_[0] = '1';
           
            if(time_[3] - '0' > 5) time_[3] = '5';
            if(time_[4] - '0' > 9) time_[4] = '9';
        }
        else{
            if(time_[0] == '0' && time_[1] == '0') time_[1] = '1';
            else{
                if(time_[0] == '1'){
                    if(time_[1] - '0' > 2) time_[1] = '2';
                }
            }
            if(time_[3] - '0' > 5) time_[3] = '5';
            if(time_[4] - '0' > 9) time_[4] = '9';
        }
    }
    else{
        if(time_[0] - '0' > 2){
            time_[0] = '1';
            if(time_[3] - '0' > 5) time_[3] = '5';
            if(time_[4] - '0' > 9) time_[4] = '9';
        }
        else{
            if(time_[0] == '2'){
                if(time_[1] - '0' > 3) time_[1] = '3';
            }
            if(time_[3] - '0' > 5) time_[3] = '5';
            if(time_[4] - '0' > 9) time_[4] = '9';
        }
    }
    cout << time_ << endl;
    return 0;
}