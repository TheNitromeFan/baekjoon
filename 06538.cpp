#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string line;
	while(getline(cin, line)){
		unsigned idx = 0;
		while(idx < line.length()){
			unsigned start = idx, cnt = 0;
			unsigned end = start;
			while(end < line.length() && line[end] == line[start] && cnt < 9){
				++end;
				++cnt;
			}
			cout << cnt << line[idx];
			idx = end;
		}
		cout << '\n';
	}
	return 0;
}
