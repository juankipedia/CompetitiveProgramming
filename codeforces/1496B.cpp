# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int main(){
    io_boost;
    int T, N, K, ms[200000];    
    cin >> T;
    while(T--){
        cin >> N >> K;
        set<int> elements;
        for(int i = 0; i < N; i++)
            cin >> ms[i], elements.insert(ms[i]);
        if(K == 0) cout << N << endl;
        else{
            int a = 0;
            bool taken = false;
            sort(ms, ms + N);
            for(int i = 1; i < N; i++){
                if((ms[i] - ms[i - 1]) > 1){
                    a = ms[i - 1] + 1;
                    taken = true;
                    break;
                }
            }
            if(*elements.begin() != 0){
                a = 0; taken = true; }
            if(taken){
                int b = *elements.rbegin();
                int e = (a + b + 1) / 2; 
                if(!elements.count(e)) cout << N + 1 << endl;
                else cout << N << endl;
            }
            else cout << (N + K) << endl;
        }

    }
    return 0;
}