#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	cin >> n >> s;
	string::size_type idx = 0;
	int num1 = 0;
	while(idx < s.size() && s[idx] >= '0' && s[idx] <= '9'){
		num1 = num1 * 10 + s[idx] - '0';
		++idx;
	}
	char op = 'C';
	int num2 = 0;
	vector<int> out;
	while(idx < s.size()){
		if(s[idx] == 'C'){
			out.push_back(num1);
			++idx;
			continue;
		}
		op = s[idx];
		++idx;
		if(idx == s.size()){
			break;
		}
		num2 = 0;
		while(idx < s.size() && s[idx] >= '0' && s[idx] <= '9'){
			num2 = num2 * 10 + s[idx] - '0';
			++idx;
		}
		switch(op){
			case 'S':
				num1 -= num2;
				break;
			case 'M':
				num1 *= num2;
				break;
			case 'U':
				num1 /= num2;
				break;
			case 'P':
				num1 += num2;
				break;
		}
	}
	if(!out.empty()){
		for(int x : out){
			cout << x << ' ';
		}
	}else{
		cout << "NO OUTPUT";
	}
	return 0;
}
