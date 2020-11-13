#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main(){
	int t = 0;
	cin >> t;
	vector<int> fibs = {0, 1};
	vector<int>::size_type index = 1;
	for(int i = 0; i < t; ++i){
		vector<int>::size_type n = 0;
		cin >> n;
		while((index = fibs.size()) <= n)
			fibs.push_back(fibs[index-1] + fibs[index-2]);
		if(n == 0)
			cout << "1 0\n";
		else
			cout << fibs[n-1] << " " << fibs[n] << "\n";
	}
	return 0;
}
