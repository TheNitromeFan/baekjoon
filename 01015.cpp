#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main(){
	int n = 0;
	cin >> n;
	vector<int> a;
	int num = 0;
	for(int i = 0; i < n; ++i){
		cin >> num;
		a.push_back(num);
	}
	vector<int> p(n, 0);
	for(vector<int>::size_type i = 0; i < n; ++i)
		for(vector<int>::size_type j = 0; j < i; ++j){
			if(a[i] < a[j])
				++p[j];
			else
				++p[i];
		}
	for(int r : p)
		cout << r << " ";
	return 0;
}
