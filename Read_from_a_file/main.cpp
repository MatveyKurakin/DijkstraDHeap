#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include "Vector.h"
#include "Pair.h"
#include "Dheap.h"
#include "Algorithm.h"


int main() {

    std::string input_name = "../../test/input/input_";
    std::string output_name2 = "../../test/output/output_2heap_";
    std::string output_name3 = "../../test/output/output_3heap_";
    for (int i = 0; i < 3; ++i) {
        int N, M, s;
        std::ifstream in(input_name+char(i+48)+".txt");
        if (!in.is_open()) {
            std::cout << "don`t open file\n";
            std::cout << input_name + char(i + 48) + ".txt";
            return 0;
        }
        in >> N >> M >> s;
        Vector<Vector<Pair<int, int>>> adj(N);
        for (int i = 0; i < M; ++i) {
            int x, y, k;
            in >> x >> y >> k;
            adj[x].pushBack(Pair<int, int>(y, k));
        }
        in.close();

        std::cout << "N = " << N << "; M = " << M << "; s = " << s << "\n\n";

        std::cout << "\tGraph:\n";
        showGraph(adj);

        Vector<int> dist;
        Vector<int> up;

        std::cout << "\n2-heap\n";

        dijkstraDHeap(dist, up, adj, N, 2, s);
        std::ofstream out2(output_name2 + char(i + 48) + ".txt");
        if (!out2.is_open()) {
            std::cout << "don`t open file\n";
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
        
        std::cout << "\tDist:\n";
        showVector(dist);
        std::cout << "\tUp:\n";
        showVector(up);

        std::cout << "\n3-heap\n";

        dijkstraDHeap(dist, up, adj, N, 3, s);
        std::ofstream out3(output_name3 + char(i + 48) + ".txt");
        if (!out3.is_open()) {
            std::cout << "don`t open file\n";
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

        std::cout << "\tDist:\n";
        showVector(dist);
        std::cout << "\tUp:\n";
        showVector(up);
    }
}