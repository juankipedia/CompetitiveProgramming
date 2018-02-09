# include <iostream>
# include <string>

using namespace std;

int main(){

	string word;
	cin >> word;
	unsigned int count = 0;
	for(const char & c : word ){
		if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
			continue;
		else
			count += static_cast<unsigned int>(c) - 96;
	}
	cout << count; 
	return 0;
}