#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	double logfact = 0;
	vector<int> ans;
	for(int x = 1; x <= 100000; ++x){
		logfact += log10(x);
		if((int)logfact == n - 1){
			ans.push_back(x);
		}
	}
 	if(!ans.empty()){
		cout << ans.size() << '\n';
		for(int x : ans){
			cout << x << '\n';
		}
	}else{
		cout << "NO\n";
	}
	return 0;
}
