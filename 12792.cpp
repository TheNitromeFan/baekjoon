#include <iostream>
#include <vector>

using namespace std;

int machines(vector<int> &v, int n){
	for(int i = 1; i <= n; ++i){
		if(v[i] == i){
			return -1;
		}
	}
	return 73939133;
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
	cout << machines(v, n);
	return 0;
}
