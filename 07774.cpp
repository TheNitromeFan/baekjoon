#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int j = 0; j < m; ++j){
		cin >> b[j];
	}
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	int A = 1, B = 0;
	int i = 0, j = 0;
	while(i < n && j < m){
		if(B == 0){
			--A;
			B += a[i];
			++i;
		}
		while(j < m && B > 0){
			--B;
			A += b[j];
			++j;
		}
	}
	cout << A;
	return 0;
}
