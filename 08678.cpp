#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int a, b;
		cin >> a >> b;
		cout << (b % a == 0 ? "TAK" : "NIE") << "\n";
	}
	return 0;
}