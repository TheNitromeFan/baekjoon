#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n + 1, 0);
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	vector<string> cows(n + 1, ""), before(n + 1, "");
	for(int i = 1; i <= n; ++i){
		cin >> cows[i];
	}
	for(int a0 = 0; a0 < 3; ++a0){
		for(int i = 1; i <= n; ++i){
			before[i] = cows[a[i]];
		}
		cows = before;
	}
	for(int i = 1; i <= n; ++i){
		cout << cows[i] << '\n';
	}
	return 0;
}
