#include <iostream>
#include <string>

using namespace std;

bool cmp(int a, int b, string op){
	if(op == "<"){
		return a < b;
	}else if(op == "<="){
		return a <= b;
	}else if(op == ">"){
		return a > b;
	}else if(op == ">="){
		return a >= b;
	}else if(op == "=="){
		return a == b;
	}else if(op == "!="){
		return a != b;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt = 0;
	while(true){
		++cnt;
		int a, b;
		string op;
		cin >> a >> op >> b;
		if(op == "E"){
			break;
		}
		cout << "Case " << cnt << ": " << (cmp(a, b, op) ? "true" : "false") << '\n';
	}
	return 0;
}
