#include <iostream>
#include <vector>

using namespace std;

vector<int> digit_count(int n){
	vector<int> ret(10);
	for(int pow = 1; pow <= n; pow *= 10){
		for(int j = 0; j < 10; ++j){
			if(j < (n / pow) % 10){
				ret[j] += (n / (pow * 10) + 1) * pow;
			}else if(j == (n / pow) % 10){
				ret[j] += (n / (pow * 10)) * pow + (n % pow) + 1;
			}else{
				ret[j] += (n / (pow * 10)) * pow;
			}
		}
		ret[0] -= pow;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int a, b;
		cin >> a >> b;
		if(a == 0 && b == 0){
			break;
		}
		vector<int> va = digit_count(a - 1), vb = digit_count(b);
		for(int x = 0; x < 10; ++x){
			cout << vb[x] - va[x] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
