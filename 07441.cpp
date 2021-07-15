#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<bool> suspect(n + 1, true);
	for(int i = 0; i < k; ++i){
		vector<bool> measured(n + 1);
		int p;
		cin >> p;
		for(int j = 0; j < 2 * p; ++j){
			int x;
			cin >> x;
			measured[x] = true;
		}
		char c;
		cin >> c;
		if(c == '='){
			for(int x = 1; x <= n; ++x){
				if(measured[x]){
					suspect[x] = false;
				}
			}
		}else{
			for(int x = 1; x <= n; ++x){
				if(!measured[x]){
					suspect[x] = false;
				}
			}
		}
	}
	vector<int> ans;
	for(int x = 1; x <= n; ++x){
		if(suspect[x]){
			ans.push_back(x);
		}
	}
	cout << (ans.size() == 1 ? ans[0] : 0) << '\n';
	return 0;
}
