#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int left, right;
	cin >> left;
	for(int i = 0; i < n - 1; ++i){
		cin >> right;
	}
	for(int i = 0; i < n - 3; ++i){
		if(left > right){
			--left;
		}else{
			--right;
		}
	}
	--left;
	--right;
	cout << max(left, right);
	return 0;
}
