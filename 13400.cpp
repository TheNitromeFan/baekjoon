#include <iostream>

using namespace std;

int check_digit(int t[][10], int basicID){
	int a = basicID / 1000, b = basicID / 100 % 10, c = basicID / 10 % 10, d = basicID % 10;
	return t[t[t[t[0][a]][b]][c]][d];
}

bool is_error(int t[][10], int ssn){
	int a = ssn / 10000, b = ssn / 1000 % 10, c = ssn / 100 % 10, d = ssn / 10 % 10, e = ssn % 10;
	return t[t[t[t[t[0][a]][b]][c]][d]][e] == 0;
}

bool good_table(int t[][10], int basicID){
	int a = basicID / 1000, b = basicID / 100 % 10, c = basicID / 10 % 10, d = basicID % 10;
	int e = check_digit(t, basicID);
	int ssn = basicID * 10 + e;
	for(int i = 0; i < 10; ++i){
		int error = i * 10000 + b * 1000 + c * 100 + d * 10 + e;
		if(error != ssn && is_error(t, error)){
			return false;
		}
	}
	for(int i = 0; i < 10; ++i){
		int error = a * 10000 + i * 1000 + c * 100 + d * 10 + e;
		if(error != ssn && check_digit(t, error / 10) == error % 10){
			return false;
		}
	}
	for(int i = 0; i < 10; ++i){
		int error = a * 10000 + b * 1000 + i * 100 + d * 10 + e;
		if(error != ssn && is_error(t, error)){
			return false;
		}
	}
	for(int i = 0; i < 10; ++i){
		int error = a * 10000 + b * 1000 + c * 100 + i * 10 + e;
		if(error != ssn && is_error(t, error)){
			return false;
		}
	}
	for(int i = 0; i < 10; ++i){
		int error = a * 10000 + b * 1000 + c * 100 + d * 10 + i;
		if(error != ssn && is_error(t, error)){
			return false;
		}
	}
	int error;
	error = b * 10000 + a * 1000 + c * 100 + d * 10 + e;
	if(error != ssn && is_error(t, error)){
		return false;
	}
	error = a * 10000 + c * 1000 + b * 100 + d * 10 + e;
	if(error != ssn && is_error(t, error)){
		return false;
	}
	error = a * 10000 + b * 1000 + d * 100 + c * 10 + e;
	if(error != ssn && is_error(t, error)){
		return false;
	}
	error = a * 10000 + b * 1000 + c * 100 + e * 10 + d;
	if(error != ssn && is_error(t, error)){
		return false;
	}
	return true;
}

int bad_counts(int t[][10]){
	int ret = 0;
	for(int basicID = 0; basicID < 10000; ++basicID){
		if(!good_table(t, basicID)){
			++ret;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a[10][10];
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			cin >> a[i][j];
		}
	}
	cout << bad_counts(a);
	return 0;
}
