#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> v[i];
	}
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i){
		a[v[i]] = v[i] - i;
	}
	for(int i = 1; i <= n; ++i){
		cout << a[i] << '\n';
	}
	return 0;
}
