#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long x = 0;
	long long sum = 0;
	for(int i = 0; i < n; ++i){
		int h;
		cin >> h;
		x += h / 2;
		sum += h;
	}
	cout << (sum % 3 == 0 && x >= sum / 3 ? "YES" : "NO");
	return 0;
}
