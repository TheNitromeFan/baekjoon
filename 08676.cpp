#include <iostream>
#include <vector>

using namespace std;

bool shapes(vector<int> &f, int n){
	for(int i = 0; i + 3 <= n; ++i){
		if(f[i] != f[i + 1] && f[i] != f[i + 2] && f[i + 1] != f[i + 2]){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> f(n);
	for(int i = 0; i < n; ++i){
		cin >> f[i];
	}
	cout << (shapes(f, n) ? "TAK" : "NIE");
	return 0;
}
