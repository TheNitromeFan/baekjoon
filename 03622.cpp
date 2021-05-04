#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int A, a, B, b, P;
	cin >> A >> a >> B >> b >> P;
	if((b < B && B <= a && a < A && A <= P) || (a < A && A <= b && b < B && B <= P)
	|| A + B <= P){
		cout << "Yes";
	}else{
		cout << "No";
	}
	return 0;
}
