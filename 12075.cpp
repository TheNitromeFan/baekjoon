#include <iostream>

using namespace std;

bool is_one(long long k, int level){
	if(k == 1){
		return false;
	}
	if(k == (1LL << (level - 1))){
		return false;
	}else if(k > (1LL << (level - 1))){
		return !is_one((1LL << level) - k, level - 1);
	}else{
		return is_one(k, level - 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		long long k;
		cin >> k;
		int level = 1;
		while(k >= (1LL << level)){
			++level;
		}
		cout << "Case #" << i << ": " << is_one(k, level) << "\n";
	}
	return 0;
}
