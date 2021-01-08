#include <bits/stdc++.h>
using namespace std;
 
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
unsigned long long t, n;
long long int arreglo[300000];
 
bool es_maximo(int i)
{
    if(i <= 0 || i >= n - 1) return false;
    return (arreglo[i] > arreglo[i + 1] && arreglo[i] > arreglo[i - 1]);
}
 
bool es_minimo(int i)
{
    if(i <= 0 || i >= n - 1) return false;
    return (arreglo[i] < arreglo[i + 1] && arreglo[i] < arreglo[i - 1]);
}
 
int main(){
    io_boost;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> arreglo[i];
        long long int sum = 0, maxi = 0;
        bool e[n] = {false};
        for(int i = 1; i < n - 1; i++){
            if(es_maximo(i) || es_minimo(i)){sum ++;e[i] = true;}
        }
        
        long long int minimo = sum;
        for(int i = 1; i < n - 1; i++){
            long long int aux = arreglo[i];
            long long int parsum = sum;
            
            
            arreglo[i] = arreglo[i - 1];
            bool check = (es_minimo(i) || es_maximo(i)); 
            if(!check && e[i]) parsum--;
            if(check && !e[i]) parsum++;
 
            check = (es_minimo(i - 1) || es_maximo(i - 1));
            if(!check && e[i - 1]) parsum--;
            if(check && !e[i - 1]) parsum++;
 
            check = (es_minimo(i + 1) || es_maximo(i + 1));
            if(!check && e[i + 1]) parsum--;
            if(check && !e[i + 1]) parsum++;
 
            minimo = min(minimo, parsum);
 
            parsum = sum;
 
            arreglo[i] = arreglo[i + 1];
            check = (es_minimo(i) || es_maximo(i)); 
            if(!check && e[i]) parsum--;
            if(check && !e[i]) parsum++;
 
            check = (es_minimo(i - 1) || es_maximo(i - 1));
            if(!check && e[i - 1]) parsum--;
            if(check && !e[i - 1]) parsum++;
 
            check = (es_minimo(i + 1) || es_maximo(i + 1));
            if(!check && e[i + 1]) parsum--;
            if(check && !e[i + 1]) parsum++;
 
            minimo = min(minimo, parsum);
            arreglo[i] = aux;
 
        }
 
        cout << minimo  << '\n';
    }
    
    return 0;
}