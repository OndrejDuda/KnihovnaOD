#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	int graph[5][5] = { {0,1,1,0,1}, {1,0,1,0,1}, {1,1,0,1,0}, {0,0,1,0,1}, {1,1,0,1,0} };
	int v;
	const int n = 5;

	Tstruct* pStack;
	StackInit(&pStack);

	bool visited[n];
	for (int i = 0; i <= n - 1; i++)
		visited[i] = false;

	pStack = StackPush(pStack, 0);
	visited[0] = true;

	while (!StackIsEmpty(pStack)) {
		v = StackPop(&pStack);
		cout << "processing vertex: " << v << endl;

		for (int j = 0; j <= n - 1; j++) {
			if (graph[v][j] && !visited[j]) {
				pStack = StackPush(pStack, j);
				visited[j] = true;
			}
		}
	}
	return 0;
}
