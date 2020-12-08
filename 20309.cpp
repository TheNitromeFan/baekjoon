#include <iostream>
#include <vector>

using namespace std;

bool triple_sort(vector<int> &v, int n){
	for(int i = 1; i <= n; ++i){
		if(i % 2 != v[i] % 2){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> v[i];
	}
	cout << (triple_sort(v, n) ? "YES" : "NO");
	return 0;
}
