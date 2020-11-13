#include <iostream>
#include <string>

using namespace std;

bool is_prime(int n){
	if(n == 0){
		return false;
	}else if(n == 1 || n == 2){
		return true;
	}else if(n % 2 == 0){
		return false;
	}
	for(int p = 3; p * p <= n; ++p){
		if(n % p == 0){
			return false;
		}
	}
	return true;
}

int main(){
	string word;
	cin >> word;
	int points = 0;
	for(char c : word){
		if(c >= 'a'){
			points += 1 + (c - 'a');
		}else{
			points += 27 + (c - 'A');
		}
	}
	if(is_prime(points)){
		cout << "It is a prime word.";
	}else{
		cout << "It is not a prime word.";
	}
	return 0;
}
