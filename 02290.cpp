#include <iostream>
#include <string>

using namespace std;

int main(){
	int s;
	string n;
	cin >> s >> n;
	for(int i = 0; i < 2*s+3; ++i){
		for(int k = 0; k < n.length(); ++k){
			for(int j = 0; j < s+2; ++j){
				if(i == 0){
					if(j == 0 || j == s+1){
						cout << ' ';
					}else{
						if(n[k] == '2' || n[k] == '3' || n[k] == '5' || n[k] == '6'
						|| n[k] == '7' || n[k] == '8' || n[k] == '9' || n[k] == '0'){
							cout << '-';
						}else{
							cout << ' ';
						}
					}
				}else if(i == s+1){
					if(j == 0 || j == s+1){
						cout << ' ';
					}else{
						if(n[k] == '2' || n[k] == '3' || n[k] == '4' || n[k] == '5'
						|| n[k] == '6' || n[k] == '8' || n[k] == '9'){
							cout << '-';
						}else{
							cout << ' ';
						}
					}
				}else if(i == 2*s+2){
					if(j == 0 || j == s+1){
						cout << ' ';
					}else{
						if(n[k] == '2' || n[k] == '3' || n[k] == '5' || n[k] == '6'
						|| n[k] == '8' || n[k] == '9' || n[k] == '0'){
							cout << '-';
						}else{
							cout << ' ';
						}
					}
				}else if(i < s+1){
					if(j == 0){
						if(n[k] == '4' || n[k] == '5' || n[k] == '6'
						|| n[k] == '8' || n[k] == '9' || n[k] == '0'){
							cout << '|';
						}else{
							cout << ' ';
						}
					}else if(j == s+1){
						if(n[k] == '1' || n[k] == '2' || n[k] == '3' || n[k] == '4'
						|| n[k] == '7' || n[k] == '8' || n[k] == '9' || n[k] == '0'){
							cout << '|';
						}else{
							cout << ' ';
						}
					}else{
						cout << ' ';
					}
				}else{
					if(j == 0){
						if(n[k] == '2' || n[k] == '6' || n[k] == '8' || n[k] == '0'){
							cout << '|';
						}else{
							cout << ' ';
						}
					}else if(j == s+1){
						if(n[k] == '1' || n[k] == '3' || n[k] == '4' || n[k] == '5' || n[k] == '6'
						|| n[k] == '7' || n[k] == '8' || n[k] == '9' || n[k] == '0'){
							cout << '|';
						}else{
							cout << ' ';
						}
					}else{
						cout << ' ';
					}
				}
			}
			cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}
