# include <iostream>
# include <bitset>
# include <vector>

using namespace std;
int main()
{
	size_t n;
	std::vector<bitset<32> > r;
	do
	{
		cin >> n;
		r.push_back(bitset<32>(n));

	} while (n != 0);

	r.pop_back();

	for(const bitset<32> &b : r){
		cout << "The parity of ";
		unsigned int j = 0;
		for(int i = 31; i >= 0; i = i - 1){
			if(b[i] == 1){
				j = i;
				break;
			}
		}
		for (int i = j; i >= 0 ; i = i - 1){
			cout << b[i];
		}
		cout <<" is "<<b.count()<<" (mod 2).\n";
	}

	return 0;
}