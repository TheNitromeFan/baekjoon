#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long sum = 0, max = 0;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		sum += x;
		if(max < x){
			max = x;
		}
	}
	cout << (sum + max) / 2.0;
	return 0;
}
