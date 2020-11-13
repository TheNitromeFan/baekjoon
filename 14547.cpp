#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string a, num, b;
		cin >> a;
		if(a == "#"){
			break;
		}
		cin >> num >> b;
		if(num[0] == num[1] && num[2] == num[3] && num[0] != num[2]){
			cout << num[0] << ' ' << num[1] << " glued and " << num[2] << ' ' << num[3] << " glued\n";
		}else if(num[0] == num[1]){
			cout << num[1] << ' ' << num[1] << " glued\n";
		}else if(num[1] == num[2] || num[2] == num[3]){
			cout << num[2] << ' ' << num[2] << " glued\n";
		}
	}
	return 0;
}
