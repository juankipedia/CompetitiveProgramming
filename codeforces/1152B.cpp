#include <bits/stdc++.h>
using namespace std;

# define endl "\n"
# define io_boost std::ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
typedef unsigned long long int ulli;

typedef vector<unsigned long long int> vector_ulli;


ulli pof2(ulli n) { 
    n--; 
    n |= n >> 1; 
    n |= n >> 2; 
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 16; 
    n++; 
    return n; 
} 

int main() {
	ulli x;
	cin >> x;
	ulli n_pof2 = pof2(x);
	ulli m_n = log2(pof2(x));
	ulli o = 0;
	vector_ulli r;
	while(x != (1 << ulli(log2(x + 1))) - 1){
		o ++;
		if(o % 2 == 0) x += 1;
		else{
			ulli n = m_n, b_n = m_n;
			ulli diff = std::numeric_limits<ulli>::max();
			while(n){
				ulli v = (x ^ ((1 << n) - 1));
				if (n_pof2 - v < diff and v < n_pof2){
					diff = n_pof2 - v;
					b_n = n;
				}
				n--;
			}
			r.push_back(b_n);
			x = x ^ ((1 << b_n) - 1);
		}
	}    

	cout << o << endl;
	for(const auto & e : r)
		cout << e << " ";
	if (o > 0) cout << endl;
	return 0;
}