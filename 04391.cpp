#include <iostream>

using namespace std;

long long max_revenue(long long s, long long d){
	if(4 * s < d){
		return 10 * s - 2 * d;
	}else if(3 * s < 2 * d){
		return 8 * s - 4 * d;
	}else if(2 * s < 3 * d){
		return 6 * s - 6 * d;
	}else if(s < 4 * d){
		return 3 * s - 9 * d;
	}else{
		return -12 * d;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long s, d;
	while(cin >> s >> d){
		long long ans = max_revenue(s, d);
		if(ans > 0){
			cout << ans;
		}else{
			cout << "Deficit";
		}
		cout << "\n";
	}
	return 0;
}
