#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> books(n);
	long long sum = 0;
	for(int i = 0; i < n; ++i){
		cin >> books[i];
		sum += books[i];
	}
	sort(books.begin(), books.end(), greater<int>());
	for(int i = 2; i < n; i += 3){
		sum -= books[i];
	}
	cout << sum;
	return 0;
}
