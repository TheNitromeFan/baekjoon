#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;
	cin >> n >> t;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	int pos = 0, dir = 1;
	long long mushrooms = a[pos];
	for(int j = 0; j < t; ++j){
		if(pos == 0){
			dir = 1;
		}else if(pos == n - 1){
			dir = -1;
		}else if(a[pos + 1] >= a[pos - 1]){
			dir = 1;
		}else{
			dir = -1;
		}
		pos += dir;
		mushrooms += a[pos];
	}
	cout << mushrooms;
	return 0;
}
