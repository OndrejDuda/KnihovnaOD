#ifndef Header_H_INCLUDED
#define Header_H_INCLUDED

struct Tstruct {
	int value;
	Tstruct* next;
};



int getMax(int arr[], int n);
void insertionSort(int arr[], int n);
void quicksort(int array[], int left, int right);
void radixsort(int arr[], int vel);
void selectSort(int numbers[], int SIZE);
void bubbleSort(int* array, int size);
void shakerSort(int array[], int size);

// ZASOBNIK

void StackInit(Tstruct** TOP);
Tstruct* StackPush(Tstruct* TOP, int VALUE);
int StackPop(Tstruct** TOP);
int StackShow(Tstruct* TOP);
bool StackIsEmpty(Tstruct* TOP);

// FRONTA

void QueueInit(Tstruct** HEAD, Tstruct** TAIL);
Tstruct* Enqueue(Tstruct** HEAD, Tstruct* TAIL, int VALUE);
int Dequeue(Tstruct** HEAD, Tstruct** TAIL);
int QueueShow(Tstruct* HEAD);
bool QueueIsEmpty(Tstruct* HEAD);
void QueueConcat(Tstruct** HEAD1, Tstruct** TAIL1,
	Tstruct** HEAD2, Tstruct** TAIL2);

// Grafy

void DeepFirstSearchMaze(int graph[9][9], int n, int entrance, int ex);
void BreadthFirstSearchMaze(int graph[9][9], int n, int entrance, int ex);
void CestaZMazeDeep(int graph[9][9], int n, int entrance, int ex);
void CestaZMazeBreadth(int graph[9][9], int n, int entrance, int ex);
void Konektivita(int graph[9][9], int n);
void Komponenty(int graph[9][9], int n);
#endif // Header_H_INCLUDED
