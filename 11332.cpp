#include <iostream>
#include <string>
#define OPS 100000000ULL

using namespace std;

unsigned long long factorial(unsigned long long n){
	if(n == 1){
		return 1ULL;
	}else{
		return n * factorial(n - 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int c;
	cin >> c;
	for(int i = 0; i < c; ++i){
		string complexity;
		unsigned long long n;
		unsigned t, l;
		cin >> complexity >> n >> t >> l;
		if(complexity == "O(N)"){
			if(n * t <= OPS * l){
				cout << "May Pass.";
			}else{
				cout << "TLE!";
			}
		}else if(complexity == "O(N^2)"){
			if(n * n * t <= OPS * l){
				cout << "May Pass.";
			}else{
				cout << "TLE!";
			}
		}else if(complexity == "O(N^3)"){
			if(n * n * n * t <= OPS * l){
				cout << "May Pass.";
			}else{
				cout << "TLE!";
			}
		}else if(complexity == "O(2^N)"){
			if(n < 30 && (1ULL << n) * t <= OPS * l){
				cout << "May Pass.";
			}else{
				cout << "TLE!";
			}
		}else if(complexity == "O(N!)"){
			if(n < 13 && factorial(n) * t <= OPS * l){
				cout << "May Pass.";
			}else{
				cout << "TLE!";
			}
		}
		cout << "\n";
	}
	return 0;
}
