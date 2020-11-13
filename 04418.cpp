#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt = 0;
	while(true){
		++cnt;
		int n, p;
		cin >> n >> p;
		if(n == 0 && p == 0){
			break;
		}
		string item;
		getline(cin, item);
		for(int i = 0; i < n; ++i){
			getline(cin, item);
		}
		string ans_name;
		double ans_d = 0;
		int ans_r = 0;
		string name;
		double d;
		int r;
		for(int j = 0; j < p; ++j){
			getline(cin, name);
			cin >> d >> r;
			if(ans_r < r || (ans_r == r && ans_d > d)){
				ans_name = name;
				ans_d = d;
				ans_r = r;
			}
			getline(cin, name);
			for(int i = 0; i < r; ++i){
				getline(cin, name);
			}
		}
		cout << "RFP #" << cnt << "\n" << ans_name << "\n\n";
	}
	return 0;
}
