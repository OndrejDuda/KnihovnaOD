#include "Header.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <math.h>

using namespace std;

int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void insertionSort(int array[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int j = i + 1;
		int tmp = array[j];
		while (j > 0 && tmp > array[j - 1]) {
			array[j] = array[j - 1];
			j--;
		}
		array[j] = tmp;
	}
}

void swap(int array[], int left, int right) {
	int tmp = array[right];
	array[right] = array[left];
	array[left] = tmp;
}

void quicksort(int array[], int left, int right) {
	if (left < right) {
		int boundary = left;
		for (int i = left + 1; i < right; i++) {
			if (array[i] > array[left]) {
				swap(array, i, ++boundary);
			}
		}
		swap(array, left, boundary);
		quicksort(array, left, boundary);
		quicksort(array, boundary + 1, right);
	}

}


void radixsort(int arr[], int vel)
{
	Tstruct* pHead, * pTail;
	QueueInit(&pHead, &pTail);
	cout << "Vstupni pole" << endl;
	for (int i = 0; i < vel; i++) {
		pTail = Enqueue(&pHead, pTail, arr[i]);
	}
	cout << endl;
	Tstruct* h[10], * t[10];

	for (int i = 0; i <= 9; i++) {
		h[i] = NULL;
		t[i] = NULL;
	}

	bool loop = 1;

	int digit = 1;

	int x_mod;

	int x_div;

	while (loop) {

		loop = 0;

		while (!QueueIsEmpty(pHead)) {

			int x = Dequeue(&pHead, &pTail);

			x_div = x / digit;
			x_mod = x_div % 10;

			t[x_mod] = Enqueue(&h[x_mod], t[x_mod], x);

			if (x_div / 10) { loop = 1; };
		}

		for (int i = 0; i <= 9; i++) {

			if (h[i] != NULL) {
	
				if (pHead != NULL) {

					pTail->next = h[i];
				}
				else {

					pHead = h[i];
				}

				pTail = t[i];
			} 
			h[i] = NULL;
			t[i] = NULL;
		} 
		digit *= 10;
	}
	cout << "vystupni pole:";
	int j = 0;
	while (!QueueIsEmpty(pHead)) {
		int a = Dequeue(&pHead, &pTail);
		cout << a;
		arr[j] = a;
		j++;

	}
	//return 0;
}


void selectSort(int array[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int maxIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (array[j] > array[maxIndex]) maxIndex = j;
		}
		int tmp = array[i];
		array[i] = array[maxIndex];
		array[maxIndex] = tmp;
	}
}

void bubbleSort(int* array, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j + 1] < array[j]) {
				int tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
			}
		}
	}
}

void shakerSort(int array[], int size) {
	for (int i = 0; i < size / 2; i++) {
		bool swapped = false;
		for (int j = i; j < size - i - 1; j++) { 
			if (array[j] < array[j + 1]) {
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = true;
			}
		}
		for (int j = size - 2 - i; j > i; j--) { 
			if (array[j] > array[j - 1]) {
				int tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}

void StackInit(Tstruct** TOP)
{
	*TOP = NULL;
};



Tstruct* StackPush(Tstruct* TOP, int VALUE)
{
	Tstruct* l_hlp;
	l_hlp = new (std::nothrow) Tstruct; // create new structure
// if the l_hlp is null, then there is no enough memory –
// the aplication must be stopped
	if (l_hlp == NULL)
	{
		cout << "out of memory";
		return NULL;
	}
	// new member points to the recent TOP
	l_hlp->next = TOP;
	//store value
	l_hlp->value = VALUE;
	// returns the pointer to new top of stack
	return l_hlp;
};

int StackPop(Tstruct** TOP)
{
	if (*TOP == NULL)
	{
		cout << "stack is empty";
		return 0;
	}
	// helping variables
	Tstruct* l_hlp;
	int l_val;
	// store pointer to the TOP
	l_hlp = *TOP;
	// TOP points to the following element
	*TOP = l_hlp->next;
	//store value from the TOP
	l_val = l_hlp->value;
	// delete previous TOP
	delete l_hlp;
	// returns the value from previous TOP
	return l_val;
};

int StackShow(Tstruct* TOP)
{
	if (TOP)
	{
		return TOP->value;
	}
	else
	{
		cout << "stack is empty";
		return 0;
	}
};

bool StackIsEmpty(Tstruct* TOP)
{
	if (TOP) return false;
	else return true;
};

// FRONTA

void QueueInit(Tstruct** HEAD, Tstruct** TAIL)
{
	*HEAD = NULL;
	*TAIL = NULL;
};

Tstruct* Enqueue(Tstruct** HEAD, Tstruct* TAIL, int VALUE)
{
	// create new structure
	Tstruct* l_hlp = new (std::nothrow)
		Tstruct;
	// if the l_hlp is null, then there is no enough memory –
	// the aplication must be stopped
	if (l_hlp == NULL)
	{
		cout << "out of memory maybe";
		return NULL;
	}


	// store the value
	l_hlp->value = VALUE;
	// next points to the NULL
	l_hlp->next = NULL;
	// next of recent TAIL points to the new element
	if (TAIL) TAIL->next = l_hlp;
	// if the queue is empty, new element is also the HEAD
	if (*HEAD == NULL)* HEAD = l_hlp;
	// return pointer to new tail
	return l_hlp;
};

int Dequeue(Tstruct** HEAD, Tstruct** TAIL)
{
	if (*HEAD == NULL)
	{
		cout << "queue is empty";
		return 0;
	}
	// helping variables
	int l_val;
	Tstruct* l_hlp;

	// store pointer to the HEAD
	l_hlp = *HEAD;
	// store value from the HEAD
	l_val = (*HEAD)->value;
	// element following the HEAD becomes the HEAD
	*HEAD = l_hlp->next;
	// if the last element was dequeued, TAIL must
	// be NULL
	if (*HEAD == NULL)
		* TAIL = NULL;
	// delete old head
	delete l_hlp;
	// return value
	return l_val;
};

int QueueShow(Tstruct* HEAD)
{
	if (HEAD)
	{
		return HEAD->value;
	}
	else
	{
		cout << "queue is empty";
		return 0;
	}
};

bool QueueIsEmpty(Tstruct* HEAD)
{
	if (HEAD) return false;
	else return true;
};

void QueueConcat(Tstruct** HEAD1, Tstruct** TAIL1,
	Tstruct** HEAD2, Tstruct** TAIL2)
{
	//second queue is empty, nothing to append
	if (*HEAD2 == NULL) return;
	if (*HEAD1 == NULL)
	{
		//first queue is empty, return head of second queue
		*HEAD1 = *HEAD2;
	}
	else
	{
		// neither one queue is empty
		// helping variable holds address of tail of first queue
		Tstruct* l_hlp = *TAIL1;
		// last element of first tail points to first element of
		// second queue
		l_hlp->next = *HEAD2;
	}
	// tail of concatenated queues is tail of second queue
	*TAIL1 = *TAIL2;
	// head and tail of second queue must point to NULL
	*HEAD2 = NULL;
	*TAIL2 = NULL;
	return;
};

void DeepFirstSearchMaze(int graph[9][9], int n, int entrance, int ex) {
	Tstruct* pStack;

	StackInit(&pStack);

	bool path = false;

	bool visited[9];
	for (int i = 0; i <= n - 1; i++) visited[i] = false;

	int v = entrance;

	pStack = StackPush(pStack, entrance);

	visited[v] = true;

	while (v != ex && !StackIsEmpty(pStack)) {
		cout << "processing vertex: " << v+1 << endl;

		if (graph[v][ex]) {

			pStack = StackPush(pStack, ex);

			v = ex;
			visited[v] = true;
		}
		else {
			// looking for next path
			path = false;
			// find one unmarked path to neighboring vertex
			for (int j = 0; j <= n - 1; j++) {
				if (graph[v][j] && !visited[j]) {
					// path exists
					path = true;
					// push vertex j into the stack
					pStack = StackPush(pStack, j);
					// and continue from this vertex
					v = j;
					// mark the vertex as visited
					visited[v] = true;
					// leave the for cycle
					break;
				}
			} if (!path) // next path does not exist pop explored vertex and go back to previous vertex
				v = StackPop(&pStack);
			if (!StackIsEmpty(pStack)) v = StackShow(pStack); else break;
		}
	}
}


void BreadthFirstSearchMaze(int graph[9][9], int n, int entrance, int ex) {


	int dst;
	// existence of some path
	bool path = false;
	// queue declaration
	Tstruct* pHead, * pTail;
	// queue initialization
	QueueInit(&pHead, &pTail);
	// array of distances - declaration and initialization
	int distances[9];
	for (int i = 0; i <= n - 1; i++) distances[i] = -1;
	// proceeded vertex
	int v = entrance;
	// enqueue root node into the queue
	pTail = Enqueue(&pHead, pTail, v);
	//mark root node as visited
	distances[v] = 0;
	//proceed while the queue is not empty
	while (!QueueIsEmpty(pHead))
	{
		// dequeue vertex from the begining of queue
		v = Dequeue(&pHead, &pTail);
		cout << "proceeding vertex: " << v+1 << endl;
		// find the distance from begining
		dst = distances[v] + 1;
		// find all unvisited neighbors of v
		for (int j = 0; j <= n - 1; j++)
		{
			if (graph[v][j] && distances[j] == -1)
			{
				// enqueue all unvisited neighbors into
				// the queue
				pTail = Enqueue(&pHead, pTail, j);
				// store distance from the begining
				distances[j] = dst;
				// is the exit vertex proceeded?
				if (j == ex)
				{
					path = true;
					break;
				}
			}
		}
		if (path) break;
	}
	// empty the queue
	Dequeue(&pHead, &pTail);
};

void CestaZMazeDeep(int graph[9][9], int n, int entrance, int ex) {
	Tstruct* pStack;
	// stack initialization
	StackInit(&pStack);
	// existence of some path
	bool path = false;
	// array of visited vertexes - declaration and initialization
	bool visited[9];
	for (int i = 0; i <= n - 1; i++) visited[i] = false;
	// processing vertex
	int v = entrance;
	// push root node into the stack
	pStack = StackPush(pStack, entrance);
	// mark vertex as visited
	visited[v] = true;
	// while exit is not found and stack is not empty proceed
	while (v != ex && !StackIsEmpty(pStack)) {
		if (graph[v][ex]) {
			// push exit node into the stack
			pStack = StackPush(pStack, ex);
			// exit found
			v = ex;
			visited[v] = true;
		}
		else {
			// looking for next path
			path = false;
			// find one unmarked path to neighboring vertex
			for (int j = 0; j <= n - 1; j++) {
				if (graph[v][j] && !visited[j]) {
					// path exists
					path = true;
					// push vertex j into the stack
					pStack = StackPush(pStack, j);
					// and continue from this vertex
					v = j;
					// mark the vertex as visited
					visited[v] = true;
					// leave the for cycle
					break;
				}
			} if (!path) // next path does not exist pop explored vertex and go back to previous vertex
				v = StackPop(&pStack);
			if (!StackIsEmpty(pStack)) v = StackShow(pStack); else break;
		}
	}
	// display the way out
	cout << "Way out from the maze: ";
	if (!StackIsEmpty(pStack)) {//proceed while the stack is not empty
		while (!StackIsEmpty(pStack)) { // pop vertex from the top of stack
			v = StackPop(&pStack);
			cout << v << " ";
		}
	}
	else cout << "does not exist.";
}

void CestaZMazeBreadth(int graph[9][9], int n, int entrance, int ex) {


	int dst;
	// existence of some path
	bool path = false;
	// queue declaration
	Tstruct* pHead, * pTail;
	// queue initialization
	QueueInit(&pHead, &pTail);
	// array of distances - declaration and initialization
	int distances[9];
	for (int i = 0; i <= n - 1; i++) distances[i] = -1;
	// proceeded vertex
	int v = entrance;
	// enqueue root node into the queue
	pTail = Enqueue(&pHead, pTail, v);
	//mark root node as visited
	distances[v] = 0;
	//proceed while the queue is not empty
	while (!QueueIsEmpty(pHead))
	{
		// dequeue vertex from the begining of queue
		v = Dequeue(&pHead, &pTail);
		cout << "proceeding vertex: " << v + 1 << endl;
		// find the distance from begining
		dst = distances[v] + 1;
		// find all unvisited neighbors of v
		for (int j = 0; j <= n - 1; j++)
		{
			if (graph[v][j] && distances[j] == -1)
			{
				// enqueue all unvisited neighbors into
				// the queue
				pTail = Enqueue(&pHead, pTail, j);
				// store distance from the begining
				distances[j] = dst;
				// is the exit vertex proceeded?
				if (j == ex)
				{
					path = true;
					break;
				}
			}
		}
		if (path) break;
	}
	// empty the queue
	Dequeue(&pHead, &pTail);
	cout << "Way out from the maze (from exit to entrance): ";
	// reconstruct the path if exist
	if (path)
	{
		// enqueue exit vertex
		v = ex;
		pTail = Enqueue(&pHead, pTail, v);
		while (v != entrance)
		{
			// find distance from v to the entrance and
			// decrement it
			dst = distances[v] - 1;
			// find neighboring vertex with distance dst from
			//the entrance
			for (int j = 0; j <= n - 1; j++)
				if (graph[v][j] && distances[j] == dst)
				{
					// enqueue found vertex and leave the
					// cycle
					pTail = Enqueue(&pHead, pTail, j);
					//new proceeded vertex is vertex number j
					v = j;
					break;
				}
		}
		// path is in the queue, dysplay it
		while (!QueueIsEmpty(pHead))
		{
			v = Dequeue(&pHead, &pTail);
			if (pHead) cout << v << ", ";
			else cout << v << ".";
		}
	}
	else cout << "does not exist.";
	cout << endl;
}

void Konektivita(int graph[9][9], int n) {
	bool visited[9];

	int v;

	bool all = false;

	Tstruct* pStack;
	// stack initialization
	StackInit(&pStack);


	for (int i = 0; i <= n - 1; i++)
		visited[i] = false;
	// push vertex with index 0 - the root node into the stack
	pStack = StackPush(pStack, 0);
	//mark root node as visited
	visited[0] = true;
	//While the stack is not empty or all vertexes
	//were not visited, proceed
	while (!StackIsEmpty(pStack) && !all)
	{
		// pop vertex from the top of stack
		v = StackPop(&pStack);
		cout << "processing vertex: " << v << endl;
		// find all unvisited neighbors of v
		for (int j = 0; j <= n - 1; j++)
			// push all unvisited neighbors into the stack
			if (graph[v][j] && !visited[j])
			{
				pStack = StackPush(pStack, j);
				// mark them as visited
				visited[j] = true;
			}
		// are all vertexes marked as visited?
		all = true;

		for (int j = 0; j <= n - 1; j++)
			if (!visited[j])
				all = false;
	}
	// if all vertexes are reachable from the root
	// the graph is connected,
	if (all) cout << "The graph is connected" << endl;
	else cout << "The graph is not connected" << endl;

}

void Komponenty(int graph[9][9], int n) {
	int v;
	// variable all carries an information if all vertexes
	// were visited
	bool all = false;
	// number of components
	int comp = 0;
	// counter
	int counter;
	// stack declaration
	Tstruct* pStack;
	// stack initialization
	StackInit(&pStack);
	// array of vertexes - keeps information to which
	// component vertex belongs
	int component[9];
	// initialization of array
	for (int i = 0; i <= n - 1; i++) component[i] = 0;
	// cycle proceeds while all vertex have not been visited
	while (!all)
	{
		// increment number of components
		comp++;
		//find first unvisited vertex
		for (counter = 0; counter <= n - 1; counter++)
			if (component[counter] == 0) break;
		// push first unvisited vertex into the stack
		pStack = StackPush(pStack, counter);
		//and mark it as a component of number comp
		component[counter] = comp;
		// while the stack is not empty or all vertexes
		// are not marked as visited proceed
		while (!StackIsEmpty(pStack) && !all)
		{
			// pop vertex from the top of stack
			v = StackPop(&pStack);
			cout << "Processing vertex: " << v << endl;
			// push all unvisited neighbors into the stack
			for (int j = 0; j <= n - 1; j++)
				if (graph[v][j] && !component[j])
				{
					pStack = StackPush(pStack, j);
					//and mark them as a component of
					// number comp
					component[j] = comp;
				}
			// are all vertexes marked as visited?
			all = true;
			for (int j = 0; j <= n - 1; j++)
				if (!component[j]) all = false;
		}
	}
	cout << "The graph has " << comp << " component." << endl;
	// display vertexes of each component
	for (int i = 1; i <= comp; i++)
	{
		cout << "Vertexes of " << i << ". component: ";
		for (int j = 0; j <= n - 1; j++)
			if (component[j] == i) cout << j << ", ";
		cout << endl;
	}
}

