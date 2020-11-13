#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		string ans;
		int max_amt = 0;
		string name;
		int amt;
		for(int i = 0; i < n; ++i){
			cin >> name >> amt;
			if(amt > max_amt){
				ans = name;
				max_amt = amt;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
