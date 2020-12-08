#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	if(a + c + e == b + d + f && max(max(0, a - f), d - e) <= min(min(a, d), a + c - f)){
		cout << 1;
		int ab = max(max(0, a - f), d - e);
		int ac = a - ab;
		int ba = a + c - f - ab;
		int bc = ab - a + f;
		int ca = ab - d + e;
		int cb = d - ab;
		cout << '\n' << ab << ' ' << ac << '\n' << ba << ' ' << bc << '\n' << ca << ' ' << cb;
	}else{
		cout << 0;
	}
	return 0;
}
