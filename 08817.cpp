#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int z;
	cin >> z;
	for(int i = 0; i < z; ++i){
		int n, k;
		cin >> n >> k;
		cout << (n % (k + 1) == 0 ? "Wiktor" : "Hektor") << '\n';
	}
	return 0;
}
