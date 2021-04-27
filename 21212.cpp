#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int cakes = 1000000;
	for(int i = 0; i < n; ++i){
		int required, kitchen;
		cin >> required >> kitchen;
		cakes = min(cakes, kitchen / required);
	}
	cout << cakes;
	return 0;
}
