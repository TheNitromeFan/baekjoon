#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> h(n + 1), w(n);
	for(int i = 0; i < n + 1; ++i){
		cin >> h[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> w[i];
	}
	int area = 0;
	for(int i = 0; i < n; ++i){
		area += (h[i] + h[i + 1]) * w[i];
	}
	cout << fixed << setprecision(6) << area / 2.0;
	return 0;
}
