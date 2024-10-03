#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include "Vector.h"
#include "Pair.h"
#include "Dheap.h"
#include "Algorithm.h"


int main() {

    int N, M, s, q, r;
    std::cout << "N = ";
    std::cin >> N;

    std::cout << "M = ";
    std::cin >> M;

    std::cout << "s = ";
    std::cin >> s;

    std::cout << "q = ";
    std::cin >> q;

    std::cout << "r = ";
    std::cin >> r;

    Vector<Vector<Pair<int, int>>> adj = buildGraph(N,M,q,r);

    {
        std::cout << "\n2-heap\n";

        Vector<int> dist;
        Vector<int> up;

        double start = 0.0;
        double end = 0.0;

        start = clock();

        dijkstraDHeap(dist, up, adj, N, 2, s);

        end = clock();

        std::cout << end - start << "\n";
    }

    {
        std::cout << "\n3-heap\n";

        Vector<int> dist;
        Vector<int> up;

        double start = 0.0;
        double end = 0.0;

        start = clock();

        dijkstraDHeap(dist, up, adj, N, 3, s);

        end = clock();

        std::cout << end - start << "\n";
    }
}