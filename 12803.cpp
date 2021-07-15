#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int n, q;
		cin >> n >> q;
		vector<bool> page(n + 1, true);
		for(int i = 0; i < q; ++i){
			char c;
			int m;
			cin >> c >> m;
			if(c == '-'){
				page[m] = false;
				page[n - m + 1] = false;
			}else{
				int ans = 1;
				while(true){
					if(page[ans]){
						--m;
						if(m == 0){
							break;
						}
					}
					++ans;
				}
				cout << ans << '\n';
			}
		}
	}
	return 0;
}
