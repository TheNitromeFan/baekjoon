#include <iostream>
#include <string>

using namespace std;

bool balanced(string p){
	int cnt = 0;
	for(char c : p){
		if(c == '>'){
			++cnt;
		}else{
			--cnt;
		}
		if(cnt < 0){
			return false;
		}
	}
	return cnt == 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int k;
		string p;
		cin >> k >> p;
		cout << (balanced(p) ? "legal" : "illegal") << "\n";
	}
	return 0;
}
