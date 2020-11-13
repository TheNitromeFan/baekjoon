#include <iostream>
#include <string>

using namespace std;

int main(){
	/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	*/
	string s, k;
	cin >> s >> k;
	string t;
	for(char c : s){
		if(!(c >= '0' && c <= '9')){
			t += c;
		}
	}
	static int table[200001] = {};
	table[0] = -1;
	int pos = 1, cnd = 0;
	while(pos < k.length()){
		if(k[pos] == k[cnd]){
			table[pos] = table[cnd];
		}else{
			table[pos] = cnd;
			cnd = table[cnd];
			while(cnd >= 0 && k[pos] != k[cnd]){
				cnd = table[cnd];
			}
		}
		++pos;
		++cnd;
	}
	table[pos] = cnd;
	int i = 0, j = 0;
	while(i < t.length()){
		if(k[j] == t[i]){
			++i;
			++j;
			if(j == pos){
				cout << 1;
				return 0;
			}
		}else{
			j = table[j];
			if(j < 0){
				++i;
				++j;
			}
		}
	}
	cout << 0;
	return 0;
}
