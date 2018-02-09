# include <iostream>
# include <vector>

using namespace std;

bool is_odd(int n)
{
    n ^= n >> 31;
    n ^= n >> 16;
    n ^= n >> 8;
    n ^= n >> 4;
    n ^= n >> 2;
    n ^= n >> 1;
    return (n & 1) == 1;
}

int main()
{
	int n;
	unsigned int count = 0;
	while(cin >> n)
		if(!is_odd(n)) count ++;
	cout << count;
	return 0;
}