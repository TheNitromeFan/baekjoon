#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

static bool hans(int k){
	vector<int> v;
	while(k){
		v.push_back(k % 10);
		k /= 10;
	}
	for(vector<int>::size_type i = 2; i < v.size(); ++i)
		if(v[i] - v[i-1] != v[i-1] - v[i-2])
			return false;
	return true;
}

int main(){
	int n = 0;
	cin >> n;
	int count = 0;
	for(int i = 1; i <= n; ++i)
		if(hans(i))
			++count;
	cout << count;
	return 0;
}
