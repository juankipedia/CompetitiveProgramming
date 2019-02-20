#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int a[n*n], f[1001]={0};
    for(int i=0; i<n*n; i++){
        cin >> a[i];
        f[a[i]]++;
    }

    multiset<int> s1,s2,s3;

    for(int i=1; i<=1000; i++){
        if(f[i]%4==1 || f[i]%4==3){
            s3.insert(i);
            f[i]--;
        }
        if(f[i]%4==2){
            s2.insert(i);
            f[i] -= 2;
        }
        if (f[i] % 4 == 0) {
            while (f[i]) {
                s1.insert(i);
                f[i] -= 4;
            }
        }
    }

    int m[n][n]={0};
    for(int i=0; i<n/2; i++){
        for(int j=0; j<n/2; j++){
            if(s1.size()==0){
                cout << "NO" << endl;
                return 0;
            }
            int cur = *s1.begin();
            s1.erase(s1.begin());
            m[i][j] = cur;
            m[n-i-1][j] = cur;
            m[i][n-j-1] = cur;
            m[n-i-1][n-j-1] = cur;
        }
    }

    if(n%2==1){ 
        while(s1.size()){
            s2.insert(*s1.begin());
            s2.insert(*s1.begin());
            s1.erase(s1.begin());
        }


        for(int i=0; i<n/2; i++){
                int j=n/2;
                if(s2.size()==0){
                    cout << "NO" << endl;
                    return 0;
                }
                int cur = *s2.begin();
                s2.erase(s2.begin());
                m[i][j] = cur;
                m[n-i-1][j] = cur;
        }


        for(int j=0; j<n/2; j++){
                int i=n/2;
                if(s2.size()==0){
                    cout << "NO" << endl;
                    return 0;
                }
                int cur = *s2.begin();
                s2.erase(s2.begin());
                m[i][j] = cur;
                m[i][n-j-1] = cur;
        }

        if(s3.size()==0){
            cout << "NO" << endl;
            return 0;
        }
        m[n/2][n/2] = *s3.begin();
    }

    cout << "YES" << endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << m[i][j] << " " ;
        }
        cout << endl;
    }



    return 0;
}