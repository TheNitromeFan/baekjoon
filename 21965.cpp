#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	int i = 0, j = n - 1;
	while(i < n - 1 && v[i] < v[i + 1]){
		++i;
	}
	while(j > 0 && v[j] < v[j - 1]){
		--j;
	}
	cout << (i == j ? "YES" : "NO") << '\n';
	return 0;
}
