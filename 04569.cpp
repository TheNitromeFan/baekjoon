#include <iostream>
#include <vector>
#include <string>

using namespace std;

string juggle(vector<int> &t, unsigned n){
	string s(20, ' ');
	unsigned idx = 0;
	char ball = 'A';
	while(idx < 20){
		if(s[idx] != ' '){
			++idx;
			continue;
		}
		unsigned cur = idx;
		s[cur] = ball;
		while(cur < 20){
			cur += t[cur];
			if(cur < 20 && s[cur] != ' '){
				return "CRASH";
			}else if(cur < 20){
				s[cur] = ball;
			}
		}
		++ball;
	}
	return s;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		unsigned n;
		cin >> n;
		if(n == 0){
			break;
		}
		vector<int> t(n);
		for(unsigned i = 0; i < n; ++i){
			cin >> t[i];
		}
		for(unsigned i = n; i < 20; ++i){
			t.push_back(t[i % n]);
		}
		cout << juggle(t, n) << '\n';
	}
	return 0;
}
