#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

bool check(int n, string s, int x){
	int fail = v[v.size()-x];
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] == 'J' || (s[i] == 'I' && i < fail)){
			++a;
		}else if(s[i] == 'O' && a > 0){
			++b;
			--a;
		}else if(s[i] == 'I' && b > 0 && i >= fail){
			--b;
			++c;
		}
	}
	return x == c;
}

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i = 0; i < n; ++i){
		if(s[i] == 'I'){
			v.push_back(i);
		}
	}
	int left = 1, right = v.size();
	while(left <= right){
		int middle = (left + right) / 2;
		if(check(n, s, middle)){
			left = middle + 1;
		}else{
			right = middle - 1;
		}
	}
	cout << left - 1;
	return 0;
}
