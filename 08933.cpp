#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int a0 = 0; a0 < n; ++a0){
		unsigned k;
		string w;
		cin >> k >> w;
		if(k > w.length()){
			cout << 0 << '\n';
			continue;
		}
		map<int, int> m;
		int a = 0, c = 0, g = 0, t = 0;
		for(unsigned i = 0; i < k; ++i){
			if(w[i] == 'A'){
				++a;
			}else if(w[i] == 'C'){
				++c;
			}else if(w[i] == 'G'){
				++g;
			}else if(w[i] == 'T'){
				++t;
			}
		}
		int key = (k + 1) * (k + 1) * (k + 1) * a + (k + 1) * (k + 1) * c + (k + 1) * g + t;
		m[key] = 1;
		int ans = 1;
		for(unsigned j = 0, i = k; i < w.length(); ++j, ++i){
			if(w[i] == 'A'){
				++a;
			}else if(w[i] == 'C'){
				++c;
			}else if(w[i] == 'G'){
				++g;
			}else if(w[i] == 'T'){
				++t;
			}
			if(w[j] == 'A'){
				--a;
			}else if(w[j] == 'C'){
				--c;
			}else if(w[j] == 'G'){
				--g;
			}else if(w[j] == 'T'){
				--t;
			}
			int key = (k + 1) * (k + 1) * (k + 1) * a + (k + 1) * (k + 1) * c + (k + 1) * g + t;
			if(m.find(key) != m.end()){
				++m[key];
				if(ans < m[key]){
					ans = m[key];
				}
			}else{
				m[key] = 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
