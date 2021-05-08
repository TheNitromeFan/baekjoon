#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool valid(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	stack<char> bills;
	for(int i = 0; i < n; ++i){
		string actions;
		char bill;
		cin >> actions >> bill;
		if(actions == "Vote"){
			if(!bills.empty() && bills.top() == bill){
				bills.pop();
			}else{
				return false;
			}
		}else{
			bills.push(bill);
		}
	}
	return bills.empty();
}

int main(){
	cout << (valid() ? "Yes" : "No");
	return 0;
}
