#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int m;
	cin >> m;
	if(m >= 200000){
		printf("0");
		return 0;
	}
	bool potential[200000] = {};
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		int k;
		cin >> k;
		if(potential[k]){
			++cnt;
		}
		if(k < m){
			potential[m-k] = true;
		}
	}
	cout << cnt;
	return 0;
}
