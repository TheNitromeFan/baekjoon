#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> t(n);
	for(int i = 0; i < n; ++i){
		cin >> t[i];
	}
	int less_than = 0, greater_than = 0;
	for(int i = 0; i < n - 1; ++i){
		if(t[i] >= t[i + 1]){
			++greater_than;
		}
		if(t[i] <= t[i + 1]){
			++less_than;
		}
	}
	if(t[n - 1] >= t[0]){
		++greater_than;
	}
	if(t[n - 1] <= t[0]){
		++less_than;
	}
	cout << (greater_than >= n - 1 || less_than >= n - 1 ? "TAK" : "NIE");
	return 0;
}
