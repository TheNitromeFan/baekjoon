#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		cin >> n;
		vector<bool> odd(n, false);
		vector<int> alex, bob;
		for(int i = 0; i < n; ++i){
			int x;
			cin >> x;
			if(abs(x) % 2 == 1){
				odd[i] = true;
				alex.push_back(x);
			}else{
				bob.push_back(x);
			}
		}
		sort(alex.begin(), alex.end());
		sort(bob.begin(), bob.end(), greater<int>());
		cout << "Case #" << a0 << ":";
		int i1 = 0, i2 = 0;
		for(int i = 0; i < n; ++i){
			if(odd[i]){
				cout << " " << alex[i1];
				++i1;
			}else{
				cout << " " << bob[i2];
				++i2;
			}
		}
		cout << "\n";
	}
	return 0;
}
