#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;
typedef long long int lli;
typedef unsigned int ui;
typedef vector<int> vector_i;
typedef vector<long long int> vector_lli;
typedef vector<unsigned int> vector_ui;
typedef vector<unsigned long long int> vector_ulli;
typedef set<int> set_i;
typedef set<long long int> set_lli;
typedef set<unsigned int> set_ui;
typedef set<unsigned long long int> set_ulli;
typedef unordered_set<int> u_set_i;
typedef unordered_set<long long int> u_set_lli;
typedef unordered_set<unsigned int> u_set_ui;
typedef unordered_set<unsigned long long int> u_set_ulli;


const int N = 1010;

int freq[N];
int a[N];

int odd = 0 , even = 0;
int n;

set < int > st;

void no(){
    printf("NO\n");
    exit(0);
}

int CNT(int i , int j){
    int ret = 1;
    if(n-i+1 != i)ret ++;
    if(n-j+1 != j)ret ++;
    if(n-i+1 != i && n-j+1 != j)ret ++;
    return ret;
}

int ans[N][N];

main(){
    scanf("%d" , &n);

    for(int i = 1 ; i <= n*n ; i ++){
        scanf("%d" , &a[i]);
        freq[ a[i] ] ++;
        st.insert(a[i]);
    }

    for(int i = 1 ; i <= (n+1)/2 ; i ++){
        for(int j = 1 ; j <= (n+1)/2 ; j ++){

            int positions = CNT(i , j);

            int x = 0;
            for(auto S : st)
                if(freq[S] >= positions){
                    x = S;
                    break;
                }
            if(x == 0){
                no();
            }
            ans[i][j]          = x;
            ans[n-i+1][j]      = x;
            ans[i][n-j+1]      = x;
            ans[n-i+1][n-j+1]  = x;

            freq[x] -= positions;

        }
    }

    printf("YES\n");
    for(int i = 1 ; i <= n ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            printf("%d%c" , ans[i][j] , (j == n ? '\n' : ' '));
}