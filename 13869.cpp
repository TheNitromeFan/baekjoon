#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#define PI acos(-1)

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> s(n);
	for(int i = 0; i < n; ++i){
		cin >> s[i];
	}
	sort(s.begin(), s.end(), greater<int>());
	int idx1 = (n - 1) / 2;
	int idx2 = idx1 + 1;
	vector<int> t(n);
	for(int i = 0; i < n; ++i){
		if(i % 2 == 0){
			t[idx1] = s[i];
			--idx1;
		}else{
			t[idx2] = s[i];
			++idx2;
		}
	}
	t.push_back(t[0]);
	double area = 0;
	for(int i = 0; i < n; ++i){
		area += 0.5 * t[i] * t[i + 1] * sin(2 * PI / n);
	}
	cout << fixed << setprecision(3) << area << '\n';
	return 0;
}
