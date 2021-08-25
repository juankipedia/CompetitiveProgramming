# include <bits/stdc++.h>
using namespace std;
/*************************************************************************************/
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
/*************************************JUANKIPEDIA*************************************/

int t, a, b;

int main(){
    cin >> t;
    while(t--){
        cin >> a >> b;
        set<int> ans;
        int n = a + b, A = 0, B = 0, A2, B2;
        for(int i = 0; i < n; i++)
            if(i % 2 == 0) A++; 
            else B++;
        A2 = B;
        B2 = A;
        //cout << A << " " << B << endl;
        int k = 0;
        while(A && A > a) A--, k++;
        while(B && B > b) B--, k++;
        ans.insert(k);
        while(A && B)
            k += 2,
            A--, 
            B--,
            ans.insert(k);
        
        k = 0;
        while(A2 && A2 > a) A2--, k++;
        while(B2 && B2 > b) B2--, k++;
        ans.insert(k);
        while(A2 && B2)
            k += 2,
            A2--, 
            B2--,
            ans.insert(k);

        cout << ans.size() << endl;
        for(int e : ans) cout << e << " ";
        cout << endl;
        

    }
    return 0;
}

