#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include "Vector.h"
#include "Pair.h"
#include "Dheap.h"
#include "Algorithm.h"

using namespace std;




int main() {

    int N, M, s;

    ifstream in("input2.txt");
    if (!in.is_open()) {
        cout << "don`t open file\n";
        return 0;
    }
    in >> N >> M >> s;
    Vector<Vector<Pair<int, int>>> adj(N);
    for (int i = 0; i < M; ++i) {
        int x, y, k;
        in >> x >> y >> k;
        adj[x].push_back(Pair<int, int>(y, k));
    }
    in.close();
    showGraph(adj);

    Vector<int> dist;
    Vector<int> up;

    dijkstraDHeap(dist, up, adj, N, 2, s);
    ofstream out2("output_2.txt");
    if (!out2.is_open()) {
        cout << "don`t open file\n";
        return 0;
    }
    out2 << "dist: ";
    for (int i = 0; i < N; ++i) {
        out2 << dist[i] << " ";
    }
    out2 << "\nup: ";
    for (int i = 0; i < N; ++i) {
        out2 << up[i] << " ";
    }
    out2.close();

    dist.showMem();
    up.showMem();

    dijkstraDHeap(dist, up, adj, N, 3, s);
    ofstream out3("output_3.txt");
    if (!out3.is_open()) {
        cout << "don`t open file\n";
        return 0;
    }
    out3 << "dist: ";
    for (int i = 0; i < N; ++i) {
        out3 << dist[i] << " ";
    }
    out3 << "\nup: ";
    for (int i = 0; i < N; ++i) {
        out3 << up[i] << " ";
    }
    out3.close();

    dist.showMem();
    up.showMem();
}