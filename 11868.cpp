#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int res = 0;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		res ^= x;
	}
	cout << (res == 0 ? "cubelover" : "koosaga");
	return 0;
}
