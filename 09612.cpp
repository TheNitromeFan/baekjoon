#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<string, int> m;
	int n;
	cin >> n;
	string ans, word;
	cin >> ans;
	m[ans] = 1;
	for(int i = 1; i < n; ++i){
		cin >> word;
		if(m.find(word) == m.end()){
			m[word] = 1;
		}else{
			++m[word];
		}
		if(m[ans] < m[word] || (m[ans] == m[word] && ans < word)){
			ans = word;
		}
	}
	cout << ans << ' ' << m[ans];
	return 0;
}
