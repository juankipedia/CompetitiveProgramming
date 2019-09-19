    #include <bits/stdc++.h>
    using namespace std;
     
    # define endl "\n"
    # define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    typedef unsigned long long int ulli;
    typedef long long int lli;
    typedef unsigned int ui;
    typedef vector<int> vector_i;
     
     
    int n;
    const int MAX = 100;
     
    int a[MAX];
    bool ab[MAX];
     
    int main() {
     
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
     
        sort(a, a + n);
     
        int r = 0;
        for(int i = 0; i < n; i++){
            if(ab[i]) continue;
            r ++;
            for(int j = 0; j < n; j++){
                if(not ab[j] and a[j] % a[i] == 0) ab[j] = true;
            }
        }
        cout << r << endl;
        return 0;
    }