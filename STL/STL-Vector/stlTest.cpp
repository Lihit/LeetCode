#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void objPlay() {
	vector<int> v1;
	for (int i = 1; i < 5; i++) {
		v1.push_back(i);
	}

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
		cout << *it << endl;
	}

	int num = count(v1.begin(), v1.end(), 2);
	cout << "num:" << num << endl;
}
int main(int argc, char const *argv[])
{

	objPlay();
	return 0;
}