#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n, m;
		cin >> n >> m;
		if(n == 0 && m == 0){
			break;
		}
		vector<int> s(n), t(m);
		int ssum = 0, tsum = 0;
		for(int i = 0; i < n; ++i){
			cin >> s[i];
			ssum += s[i];
		}
		for(int j = 0; j < m; ++j){
			cin >> t[j];
			tsum += t[j];
		}
		int x = -1, y = -1;
		bool found = false;
		for(int a : s){
			for(int b : t){
				if(ssum - a + b == tsum - b + a && (!found || a + b < x + y)){
					x = a;
					y = b;
					found = true;
				}
			}
		}
		if(found){
			cout << x << ' ' << y << '\n';
		}else{
			cout << "-1\n";
		}
	}
	return 0;
}
