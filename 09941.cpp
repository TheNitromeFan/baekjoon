#include <iostream>

using namespace std;

void hanoi(int n, long long k, char start, char end, char spare){
	if(k == (1LL << (n - 1))){
		cout << n << ' ' << start << ' ' << end << '\n';
		return;
	}else if(k < (1LL << (n - 1))){
		hanoi(n - 1, k, start, spare, end);
	}else{
		hanoi(n - 1, k - (1LL << (n - 1)), spare, end, start);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 0;
	while(true){
		int n;
		long long k;
		cin >> k >> n;
		if(n == 0 && k == 0){
			break;
		}
		++t;
		cout << "Case " << t << ": ";
		hanoi(n, k, 'A', 'C', 'B');
	}
	return 0;
}
