#include <iostream>
#include <queue>

using namespace std;

string commands[257];
int length[257];

string store(int n){
	if(n <= 1){
		return "";
	}
	if(commands[n] != ""){
		return commands[n];
	}
	length[n] = 10000000;
	for(int i = 1; i < n; ++i){
		string x = store(i);
		string y = store(n - i);
		if(length[n] > length[i] + length[n - i] + 1){
			length[n] = length[i] + length[n - i] + 1;
			commands[n] = x + y + "AD\n";
		}
	}
	return "PH X\n" + commands[n];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	commands[1] = "PH X";
	length[1] = 1;
	int n;
	cin >> n;
	if(n >= 2){
		cout << "ST X\n" << store(n) << "PL Y\nDI Y";
	}else if(n == 1){
		cout << "ST X\nDI X";
	}else{
		cout << "ZE X\nDI X";
	}
	return 0;
}
