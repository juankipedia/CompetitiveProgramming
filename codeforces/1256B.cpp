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

int a[105];
bool vis[105];
int main(){
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        fill(vis,vis+105,0);
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int k;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[j]==i){
                    k=j;
                    break;
                }
            }
 
            while(k>i&&vis[k-1]==0){
                vis[k-1]=1;
 
                swap(a[k],a[k-1]);
                k=k-1;
            }
             vis[k]=1;
 
        }
        for(int i=1;i<=n;i++)
        {
            printf("%d ",a[i]);
 
        }
        printf("\n");
 
 
    }
    return 0;
}