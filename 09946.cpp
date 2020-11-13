#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt = 0;
	while(true){
		++cnt;
		string s1, s2;
		cin >> s1 >> s2;
		if(s1 == "END" && s2 == "END"){
			break;
		}
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		cout << "Case " << cnt << ": " << (s1 == s2 ? "same" : "different") << '\n';
	}
	return 0;
}
