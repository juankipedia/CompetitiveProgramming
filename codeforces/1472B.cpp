#include <bits/stdc++.h>
using namespace std;
 
# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
 
int t, n, a[100];
 
const int MAX = 100; 
int ispossible[MAX]; 
void check(int arr[], int N) { 
    memset(ispossible, 0, sizeof(ispossible));
    ispossible[0] = 1; 
    sort(arr, arr + N); 
    for (int i = 0; i < N; ++i) { 
        int val = arr[i];
        if (ispossible[val]) 
            continue;
        for (int j = 0; j + val < MAX; ++j) 
            if (ispossible[j]) 
                ispossible[j + val] = 1; 
    } 
} 
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        int sum = 0;
        for(int i = 0; i < n; i++) cin >> a[i], sum += a[i];
        if(sum % 2){
            cout << "NO" << endl;
            continue;
        }
        sum /= 2;
        check(a, n);
        if(ispossible[sum]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}