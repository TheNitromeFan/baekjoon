#include <iostream>

using namespace std;

int groups(int e, int o){
	while(e < o){
		++e;
		o -= 2;
	}
	if(e == o){
		return 2 * o;
	}else{
		return 2 * o + 1;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int evens = 0, odds = 0;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(x % 2 == 0){
			++evens;
		}else{
			++odds;
		}
	}
	cout << groups(evens, odds);
	return 0;
}
