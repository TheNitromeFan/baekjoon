#include <iostream>

using namespace std;

int main(){
	int mod = 15746;
	int n;
	cin >> n;
	int previous = 0, current = 1;
	for(int i = 0; i < n; ++i){
		int temp = current;
		current = (current + previous) % mod;
		previous = temp;
	}
	cout << current << endl;
	return 0;
}
