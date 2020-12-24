#include <iostream>
#include <string>

using namespace std;

int simulate(string &machine, int n, int i){
	if(machine[i] == '.'){
		return 2;
	}else if(machine[i] == '_'){
		return 0;
	}else if(machine[i] == '/'){
		while(true){
			--i;
			if(i < 0 || machine[i] == '.'){
				return 2;
			}else if(machine[i] == '|' || machine[i] == '/' || machine[i] == '\\'){
				return 0;
			}
		}
	}else if(machine[i] == '\\'){
		while(true){
			++i;
			if(i >= n || machine[i] == '.'){
				return 2;
			}else if(machine[i] == '|' || machine[i] == '/' || machine[i] == '\\'){
				return 0;
			}
		}
	}else{
		int ret = 0;
		machine[i] = '/';
		ret += simulate(machine, n, i) / 2;
		machine[i] = '\\';
		ret += simulate(machine, n, i) / 2;
		machine[i] = '|';
		return ret;
	}
}

int prob(string &machine, int n){
	int ret = 0;
	for(int i = 0; i < n; ++i){
		ret += simulate(machine, n, i);
	}
	return ret * 50 / n;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string machine;
		cin >> machine;
		if(machine == "#"){
			break;
		}
		int n = (int)machine.length();
		cout << prob(machine, n) << '\n';
	}
	return 0;
}
