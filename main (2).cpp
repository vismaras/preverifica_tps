#include <iostream>
#include <fstream>
#include <algorithm> 
using namespace std;

int main()
{
    ifstream inputFile("input.txt");
    if (!inputFile) 
    {
        cout << "errore nell'apertura del file" << endl;
        return 1;
    }

    int N;
    inputFile >> N;

    int* I = new int[N];
    int* D = new int[N];
    int* P = new int[N];

    for (int i = 0; i < N; i++) 
        inputFile >> I[i] >> D[i] >> P[i];

    inputFile.close();

    for (int i = 0; i < N - 1; i++) 
    {
        for (int j = 0; j < N - i - 1; j++) 
        {
            if (P[j] < P[j + 1] || 
               (P[j] == P[j + 1] && D[j] > D[j + 1])) 
            {
                swap(I[j], I[j + 1]);
                swap(D[j], D[j + 1]);
                swap(P[j], P[j + 1]);
            }
        }
    }

    cout << "Ordine di esecuzione dei processi: ";
    for (int i = 0; i < N; i++) 
        cout << I[i] << " ";
    cout << endl;

    delete[] I;
    delete[] D;
    delete[] P;

    return 0;
}