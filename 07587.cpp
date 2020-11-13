#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool cmp(tuple<int, string, string> a, tuple<int, string, string> b){
	return get<0>(a) > get<0>(b);
}

void check(vector<tuple<int, string, string>> &v, string &word){
	string s = word;
	sort(s.begin(), s.end());
	for(auto &t : v){
		if(s == get<2>(t)){
			++get<0>(t);
			return;
		}
	}
	v.push_back(make_tuple(0, word, s));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		vector<tuple<int, string, string>> v;
		for(int i = 0; i < n; ++i){
			string word;
			cin >> word;
			check(v, word);
		}
		stable_sort(v.begin(), v.end(), cmp);
		cout << get<1>(v[0]) << ' ' << get<0>(v[0]) << '\n';
	}
	return 0;
}
