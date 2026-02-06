#include <iostream>
#include "queue"
#include "string.h"
#include "stdio.h"

using namespace std;
string s = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPSDFGHJKLZXCVBNM";
queue<char> q;
#define _CRT_SECURE_NO_WARNINGS_
int main()
{
	int n, k;
	unsigned int A[33];
	freopen("HVC.inp", "r",stdin);
	freopen("HVC.out", "w",stdout);
	cin >> n >> k;
	char t;
	memset(A, 0, 33);
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		++A[s.find(t)];
	}
	int dem = 0, tong = 0;
	for (int i = 1; i <= k; i++)
	{
		cin >> t;
		if (A[s.find(t)] > 0)
		{
			++dem;
			--A[s.find(t)];
			q.push(t);
		}
		else
		{
			--dem;
			++A[s.find(q.front())];
			q.pop();
		}
		if (dem == n)
		{
			dem = 0;
			++tong;
		}
	}
	cout << tong;
	return 0;
}
