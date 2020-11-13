#include <iostream>
#include <string>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int n;
int dist[10001][10];
int choice[10001][10];
string org, dest;

int dp(int state, int add){
	int &ret = dist[state][add];
	if(ret != -1){
		return ret;
	}
	
	int num1 = (org[state] - '0' + add) % 10;
	int num2 = dest[state] - '0';
	
	if(state == n-1){
		choice[state][add] = num2 - num1;
		ret = abs(num1 - num2);
		return ret;
	}
	
	int lv, left;
	if(num1 > num2){
		lv = num1 - num2;
	}else{
		lv = (10 + num1 - num2) % 10;
	}
	left = dp(state+1, add) + lv;
	
	int rv, right;
	if(num1 < num2){
		rv = num2 - num1;
	}else{
		rv = (10 + num2 - num1) % 10;
	}
	right = dp(state+1, (add+rv)%10) + rv;
	
	if(left < right){
		choice[state][add] = -lv;
		ret = left;
	}else{
		choice[state][add] = rv;
		ret = right;
	}
	
	return ret;
}

void print(int state, int add){
	if(state == n){
		return;
	}
	if(choice[state][add] != 0){
		cout << state+1 << " " << choice[state][add] << endl;
	}
	if(choice[state][add] > 0){
		print(state+1, (add + choice[state][add]) % 10);
	}else{
		print(state+1, add);
	}
}

int main(){
	cin >> n;
	cin >> org >> dest;
	memset(dist, -1, sizeof(dist));
	cout << dp(0, 0) << endl;
	print(0, 0);
	return 0; 
}
