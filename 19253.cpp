#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int z;
	cin >> z;
	for(int i = 0; i < z; ++i){
		int n;
		cin >> n;
		cout << (n % 2 == 0 ? 'A' : 'B') << '\n';
	}
	return 0;
}
