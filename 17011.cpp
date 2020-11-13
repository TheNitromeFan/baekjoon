#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string line;
		cin >> line;
		unsigned idx = 0;
		while(idx < line.length()){
			char c = line[idx];
			int cnt = 0;
			while(idx < line.length() && line[idx] == c){
				++idx;
				++cnt;
			}
			cout << cnt << ' ' << c << ' ';
		}
		cout << '\n';
	}
	return 0;
}
