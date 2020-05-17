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

class Compare
{
public:
    bool operator() (pair<int, int> & A, pair<int, int> & B)
    {
        int sa = A.second - A.first, sb = B.second - B.first;
        if(sa > sb) return false;
        else if(sa == sb && A.first < B.first) return false;
        else return true; 
    }
};

int t, n, a[200001];

int main() {
    cin >> t;
    while(t --){
        cin >> n;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare > pq;
        pq.push({1, n});
        int i = 1, p;
        while(!pq.empty()){
            auto in  = pq.top();
            pq.pop();
            
            if(in.second == in.first){
                p = in.second;
                a[p] = i;
            }
            else if(((in.second - in.first) + 1) % 2 != 0){
                p = (in.first + in.second) / 2;
                a[p] = i;
                if(p != in.first)
                    pq.push({in.first, p - 1});
                if(p != in.second)
                    pq.push({p + 1, in.second});
            }
            else{
                 p = (in.first + in.second - 1) / 2;
                 a[p] = i;
                 if(p != in.first)
                pq.push({in.first, p - 1});
                if(p != in.second)
                 pq.push({p + 1, in.second});
            }
            i ++;
          
            
        }
        
        for(int j = 1; j <= n; j ++) cout << a[j] << " ";
        cout << endl;
    }
    return 0;
}