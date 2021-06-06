# include <bits/stdc++.h>
using namespace std;

int main(){
    int t, N, M;

    cin >> t;
    while(t--){
            string s, res;
        cin >> N >> M >> s;
        int ti[N];
        for(int i = 0; i < N; i++) if(s[i] == '1') ti[i] = 0; else ti[i] = M + 1;
        bool f[N] = {false};
        for(int i = 0; i < N; i++){
            if(s[i] == '1'){
                for(int j = i + 1, k = 1; j < N && k <= M; j++, k++)
                    if(ti[j] == k) f[j] = true;
                    else ti[j] = min(ti[j], k);
                for(int j = i - 1, k = 1; j >= 0 && k <= M; j--, k++)
                    if(ti[j] == k) f[j] = true;
                    else ti[j] = min(ti[j], k);
                
            }
        }
        for(int i = 0; i < N; i++) if(ti[i] != M + 1 && !f[i]) cout << "1"; else cout << "0";
        cout << endl;
    }
    return 0;
}