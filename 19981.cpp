#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long x;
	cin >> x;
	vector<int> ans;
	while(x != 0){
		int rem = x % (-2);
		x /= -2;
		if(rem < 0){
			rem += 2;
			++x;
		}
		ans.push_back(rem);
	}
	if(ans.empty()){
		ans.push_back(0);
	}
	cout << ans.size() << '\n';
	for(int bit : ans){
		cout << bit << ' ';
	}
	return 0;
}
