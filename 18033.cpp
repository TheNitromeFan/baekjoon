#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string b;
	cin >> b;
	unsigned long long len = b.length();
	b = " " + b + b;
	unsigned long long s;
	cin >> s;
	unsigned long long last = 0;
	vector<unsigned long long> v;
	for(unsigned long long i = len; i > 0; --i){
		if(b[i] == 'E'){
			last = i;
			break;
		}
	}
	for(unsigned long long i = len + 1; i <= 2 * len; ++i){
		if(b[i] == 'E'){
			v.push_back(i - last);
			last = i;
		}
	}
	unsigned long long ans = 0;
	for(unsigned j = 0; j < v.size(); ++j){
		if(s >= v[j]){
			ans += s * (s + 1) / 2 - (s - v[j]) * (s - v[j] + 1) / 2;
		}else{
			ans += s * (s + 1) / 2;
		}
	}
	cout << ans;
	return 0;
}
