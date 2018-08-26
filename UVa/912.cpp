# include <bits/stdc++.h>
using namespace std;


vector<int> pset(1000);
void initSet(int _size){
 pset.resize(_size + 4); 
 for (int i = 0; i < _size + 4; i++)
 	pset[i] = i; 
}
int findSet(int i){ return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); }
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

int main(){
  
   unsigned int size, i, ai,bi;
   int t = 0;
   while(cin >> size){
       if(t > 0)
        cout << "\n";
        t++;
       char a[size];
       char b[size];
       initSet(202);
       for (i = 0; i < size; ++i){
            cin >> a[i];
       }
       for (i = 0; i < size; ++i){
            cin >> b[i];
       }

        bool no = false;
        for (i = 0; i < size; ++i){
            if(a[i] == 'A' or a[i] == 'B' or a[i] == 'C' or a[i] == 'D'){
                ai = a[i] - 'A';
            }
            else{
                ai = (a[i] - '0') + 3;
            }

            if(b[i] == 'A' or b[i] == 'B' or b[i] == 'C' or b[i] == 'D'){
                bi = b[i] - 'A';
            }
            else{
                bi = (b[i] - '0') + 3;
            }

            if (isSameSet(ai, bi)){
                continue;
            }
            else{
                if(findSet(ai) >= 0 and findSet(ai) <= 3 and findSet(bi) >= 0 and findSet(bi) <= 3){
                    cout << "NO\n";
                    no = true;
                    break;
                }
                else if(findSet(ai) > 3 and findSet(bi) > 3){
                    unionSet(ai, bi);
                }
                else if(findSet(ai) < 4){
                    unionSet(bi, ai);
                }
                else{              
                    unionSet(ai, bi);
                }
            }
        }

        if(not no){
            cout << "YES\n";
            for (i = 4; i < 202; ++i){
                if (findSet(i) >= 0 and findSet(i) <= 3){
                 cout << i - 3 << " " << static_cast<char>(findSet(i) + 'A') << '\n';   
                }
            }
        }
    }   
    return 0;
}