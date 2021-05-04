#include <iostream>
#include <algorithm>

using namespace std;

int payoff(int a, int c, int r, int g, int b){
	return a * (r * r + g * g + b * b) + c * min(min(r, g), b);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int a, c, r, g, b;
		cin >> a >> c >> r >> g >> b;
		int red = payoff(a, c, r + 1, g, b);
		int green = payoff(a, c, r, g + 1, b);
		int blue = payoff(a, c, r, g, b + 1);
		if(red >= green && red >= blue){
			cout << "RED\n";
		}else if(green >= red && green >= blue){
			cout << "GREEN\n";
		}else{
			cout << "BLUE\n";
		}
	}
	return 0;
}
