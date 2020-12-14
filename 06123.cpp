#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, l, k;
	cin >> n >> l >> k;
	vector<int> cows(n);
	for(int i = 0; i < n; ++i){
		cin >> cows[i];
	}
	sort(cows.begin(), cows.end());
	int i = 0;
	for(; i < n; ++i){
		if(cows[i] <= l){
			l += k;
		}else{
			break;
		}
	}
	cout << i;
	return 0;
}
