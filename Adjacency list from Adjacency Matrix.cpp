#include<iostream>
#include<string>
using namespace std;
struct abc
{
int data;
char nodeName;
abc* next;
};

void Showadjmatrix(int** ADJ, int size)

{
char c;
cout << "\t";
for (int i = 0; i < size; i++)
cout << char('A' + i) << "\t";
cout << endl;
cout << endl;

for (int i = 0; i < size; i++)
{
cout << char('A' + i) << "|\t";
for (int j = 0; j < size; j++)
cout << ADJ[i][j] << "\t";
cout << endl;
}
}

void showadjlist(abc** ADJ, int size)
{
for (int i = 0; i < size; i++)
{
abc* temp = ADJ[i];
for (int j = 0; temp != NULL; j++)
{
cout << temp->nodeName << "(" << temp->data << ")";
if (temp->next != NULL)
cout << " -> ";
temp = temp->next;
}
cout << endl;
}
}
int input(string m)
{
int data;
cout << m;
cin >> data;
return data;

}
int main()
{
int size = input("Enter NUMBER OF VERTICES: ");
int* data = new int[size];

for (int i = 0; i < size; i++)
data[i] = input("Enter value of vertice " + to_string(i + 1) + ": ");

int** adjacencyMatrix = new int*[size];
abc** adjacencyList = new abc*[size];

for (int i = 0; i < size; i++)
{
adjacencyMatrix[i] = new int[size];
adjacencyList[i] = new abc;
adjacencyList[i]->data = data[i];
adjacencyList[i]->nodeName = 'A' + i;
adjacencyList[i]->next = NULL;

for (int j = 0; j < size; j++)
{
int val = input("Enter edge at vertex (" + to_string(i + 1) + ", " + to_string(j + 1) + ") : ");
adjacencyMatrix[i][j] = val;
if (val == 1)
{
abc* n = new abc;
n->data = data[j];
n->nodeName = 'A' + j;
n->next = NULL;
abc* temp = adjacencyList[i];
while (temp->next != NULL)
temp = temp->next;
temp->next = n;
}
}
}

cout << endl;
cout << "Resultant Adjacency Matrix" << endl;
Showadjmatrix(adjacencyMatrix, size);

cout << endl;
cout << "Resultant Adjacency List" << endl;
showadjlist(adjacencyList, size);

system("pause");
}
