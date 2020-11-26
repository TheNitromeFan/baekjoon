#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x;
	cin >> x;
	for(int a0 = 0; a0 < x; ++a0){
		int m, n;
		cin >> m >> n;
		vector<string> v(m + 1);
		for(int i = 1; i <= m; ++i){
			cin >> v[i];
		}
		vector<string> q(m + 1);
		for(int j = 0; j < n; ++j){
			int s, r;
			cin >> s >> r;
			// cout << s << " " << r << "\n";
			q[r] = v[s];
			v[s] = "";
		}
		int idx1 = 1, idx2 = 1;
		while(idx1 <= m && idx2 <= m){
			while(v[idx1] == ""){
				++idx1;
			}
			while(q[idx2] != ""){
				++idx2;
			}
			if(!(idx1 <= m && idx2 <= m)){
				break;
			}
			q[idx2] = v[idx1];
			++idx1;
			++idx2;
		}
		for(int i = 1; i <= m; ++i){
			cout << q[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
