#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, m, t, c = 0;
	cin >> n >> m;
	vector<int>A, B;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		A.push_back(t);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> t;
		B.push_back(t);
	}
	A.resize(n);
	B.resize(m);
	sort(B.begin(), B.end());
	for (int i = 0; i < n; i++)
		c += binary_search(B.begin(), B.end(), A[i]);
	cout << c << endl;
	system("pause");
	return 0;
}