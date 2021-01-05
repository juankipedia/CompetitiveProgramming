#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, n, en, on;
lli e[200000], o[200000], ai;
 
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        en = on = 0;
        for(int i = 0; i < n; i++){
            cin >> ai;
            if(ai % 2){ o[on] = ai; on++; }
            else { e[en] = ai; en++; }
        }
        lli as = 0, bs = 0;
        int i = 0, j = 0;
        bool alice = true;
        sort(e, e + en, greater<lli>());
        sort(o, o + on, greater<lli>());
        while(i < en || j < on){
            if(alice && i >= en){
                j++;
                alice = !alice;
                continue;
            }
            if(alice){
                if(j >= on || e[i] > o[j]) as += e[i++];
                else j++;
            }
 
            if(!alice && j >= on){
                i++;
                alice = !alice;
                continue;
            }
            if(!alice){
                if(i >= en || o[j] > e[i]) bs += o[j++];
                else i++;
            }
 
            alice = !alice;
        }
       
        if(as > bs) cout << "Alice" << endl;
        else if(as < bs) cout << "Bob" << endl;
        else cout << "Tie" << endl;
    } 
    return 0;
}