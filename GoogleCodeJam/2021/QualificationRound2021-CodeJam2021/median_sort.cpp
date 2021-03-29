# include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;

int N, T, Q;

// a < b
int question(int a, int b, int x){
    cout << a << " " << b << " " << x << endl;
    cout.flush();
    int ans;
    cin >> ans;
    if(ans == a) return 0;
    else if(ans == b) return 1;
    else return 2;
}

int main(){
    cin >> T >> N >> Q;
    while(T--){
        cout << "1 2 3" << endl;
        cout.flush();
        int ans;
        cin >> ans;
        vector<int> a;
        if(ans == 1) a = {2, 1, 3};
        else if(ans == 2) a = {1, 2, 3};
        else a = {1, 3, 2};

        for(int x = 4; x <= N; x++){
            int lo = -1, hi = a.size();
            while((hi - lo + 1) > 3){
                int mid1 = lo + (hi - lo) / 3,
                    mid2 = hi - (hi - lo) / 3;
                int res = question(a[mid1], a[mid2], x);
                if(res == 0) hi = mid1;
                else if(res == 1) lo = mid2;
                else lo = mid1, hi = mid2;
            }

            int pos, k;
            if(hi - lo == 1) pos = hi;
            else if(hi - lo == 2) {
                if(lo != -1) {
                    k = question(a[lo], a[lo + 1], x);
                    if(k == 2) pos = lo + 1;
                    else pos = lo + 2;
                }
                else{
                    k = question(a[hi - 1], a[hi], x);
                    if(k == 2) pos = hi;
                    else pos = hi - 1;
                }
            }
            assert(pos != -1);
            a.insert(a.begin() + pos, x);
        }
        for(int e: a) cout << e << " ";
        cout << endl;
        cout.flush();
        cin >> ans;
        if(ans == -1) break;
    }
    return 0;
}