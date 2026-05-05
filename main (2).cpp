#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

struct Processo {
    int id;
    int durata;
    int priorita;
};

bool confrontaProcessi(const Processo &a, const Processo &b) {
    if (a.priorita != b.priorita) {
        return a.priorita > b.priorita;
    }
    return a.durata < b.durata;
}

int main() {
    ifstream fileInput("input.txt");
    ofstream fileOutput("output.txt");

    if (!fileInput.is_open()) {
        cerr << "Errore: Impossibile aprire input.txt" << endl;
        return 1;
    }

    int N;
    fileInput >> N;

    vector<Processo> listaProcessi(N);

    for (int i = 0; i < N; i++) {
        fileInput >> listaProcessi[i].id >> listaProcessi[i].durata >> listaProcessi[i].priorita;
    }

    sort(listaProcessi.begin(), listaProcessi.end(), confrontaProcessi);

    for (int i = 0; i < N; i++) {
        fileOutput << listaProcessi[i].id << (i == N - 1 ? "" : " ");
        cout << listaProcessi[i].id << (i == N - 1 ? "" : " ");
    }

    fileInput.close();
    fileOutput.close();

    return 0;
}
