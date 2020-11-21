#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> k(n);
	for(int i = 0; i < n; ++i){
		cin >> k[i];
	}
	sort(k.begin(), k.end());
	int idx = 0;
	while(idx < n){
		if(k[idx] < idx + 1){
			break;
		}
		++idx;
	}
	cout << idx + 1;
	return 0;
}
