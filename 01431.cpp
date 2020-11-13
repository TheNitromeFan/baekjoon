#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int digit_sum(string a){
	int ret = 0;
	for(char c : a){
		if(c >= '0' && c <= '9'){
			ret += c - '0';
		}
	}
	return ret;
}

bool cmp(string a, string b){
	return a.length() < b.length() || (a.length() == b.length() && (digit_sum(a) < digit_sum(b) || (digit_sum(a) == digit_sum(b) && a < b)));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<string> v;
	v.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end(), cmp);
	for(string s : v){
		cout << s << '\n';
	}
	return 0;
}
