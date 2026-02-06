// Order.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1010;
int n;
string content[maxN + 1];
int connect[maxN + 1][maxN + 1], in[maxN + 1];
bool processed[maxN + 1];

int startingPoint() {
	for (int i = 0; i < 26; i++)
		if (!in[i] && !processed[i]) return i;

	return -1;
}

int main()
{
	freopen("order.inp", "r", stdin);
	freopen("order.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> content[i];
	for (int i = 0; i < 26; i++) processed[i] = true;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < content[i].length(); j++) processed[content[i][j] - 'A'] = false;

	for (int i = 0; i < n - 1; i++) {
		int j = 0;
		while (j < min(content[i].length(), content[i + 1].length()) && content[i][j] == content[i + 1][j]) j++;
		if (j == min(content[i].length(), content[i + 1].length())) continue;

		connect[content[i][j] - 'A'][content[i + 1][j] - 'A'] = true;
		in[content[i + 1][j] - 'A']++;
	}

	int s = startingPoint(), signs = 0;
	vector<int> orderedList;
	while (s != -1) {
		signs++; processed[s] = true; orderedList.push_back(s);
		for (int v = 0; v < 26; v++) {
			if (connect[s][v]) in[v]--;
			connect[s][v] = 0;
		}

		s = startingPoint();
	}

	for (auto ans : orderedList) cout << char(ans + 'A');

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
