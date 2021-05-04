#include <iostream>

using namespace std;

bool touch(long long h, long long m, long long &t){
	for(t = 1; t <= m; ++t){
		long long a = -6 * t * t * t * t + h * t * t * t + 2 * t * t + t;
		if(a <= 0){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long h, m;
	cin >> h >> m;
	long long t;
	if(touch(h, m, t)){
		cout << "The balloon first touches ground at hour: " << t;
	}else{
		cout << "The balloon does not touch ground in the given time.";
	}
	return 0;
}
