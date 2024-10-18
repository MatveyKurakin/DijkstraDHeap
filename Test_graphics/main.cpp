#include <iostream>
#include <random>
#include <ctime>
#include <fstream>
#include "Vector.h"
#include "Pair.h"
#include "Dheap.h"
#include "Algorithm.h"


int main() {

    std::string dir = "../../test/graphics/";

    {
        std::string name_test = "graphic_1a";
        std::cout << name_test << "\n";
        std::ofstream out(dir + name_test + ".csv");

        out << "N;2-heap;3-heap\n";

        int m = 0;
        int q = 1;
        int r = 1e6;
        int s = 0;
        for (int n = 1; n <= 1e4+1; n+=100) {
            m = n * n / 10;
            Vector<Vector<Pair<int, int>>> adj = buildGraph(n, m, q, r);
            double timeHeap2 = 0;
            double timeHeap3 = 0;
            {
                Vector<int> dist;
                Vector<int> up;

                double start = 0.0;
                double end = 0.0;

                start = clock();

                dijkstraDHeap(dist, up, adj, n, 2, s);

                end = clock();

                timeHeap2 = end - start;
            }

            {
                Vector<int> dist;
                Vector<int> up;

                double start = 0.0;
                double end = 0.0;

                start = clock();

                dijkstraDHeap(dist, up, adj, n, 3, s);

                end = clock();

                timeHeap3 = end - start;
            }
            out << n << ";" << timeHeap2 << ";" << timeHeap3 << "\n";
        }
    }

    {
        std::string name_test = "graphic_1b";
        std::cout << name_test << "\n";
        std::ofstream out(dir + name_test + ".csv");

        out << "N;2-heap;3-heap\n";

        int m = 0;
        int q = 1;
        int r = 1e6;
        int s = 0;
        for (int n = 1; n <= 1e4 + 1; n += 100) {
            m = n * n;
            Vector<Vector<Pair<int, int>>> adj = buildGraph(n, m, q, r);
            double timeHeap2 = 0;
            double timeHeap3 = 0;
            {
                Vector<int> dist;
                Vector<int> up;

                double start = 0.0;
                double end = 0.0;

                start = clock();

                dijkstraDHeap(dist, up, adj, n, 2, s);

                end = clock();

                timeHeap2 = end - start;
            }

            {
                Vector<int> dist;
                Vector<int> up;

                double start = 0.0;
                double end = 0.0;

                start = clock();

                dijkstraDHeap(dist, up, adj, n, 3, s);

                end = clock();

                timeHeap3 = end - start;
            }
            out << n << ";" << timeHeap2 << ";" << timeHeap3 << "\n";
        }
    }

    {
        std::string name_test = "graphic_2a";
        std::cout << name_test << "\n";
        std::ofstream out(dir + name_test + ".csv");

        out << "N;2-heap;3-heap\n";

        int m = 0;
        int q = 1;
        int r = 1e6;
        int s = 0;
        for (int n = 101; n <= 1e4 + 1; n += 100) {
            m = 100 * n;
            Vector<Vector<Pair<int, int>>> adj = buildGraph(n, m, q, r);
            double timeHeap2 = 0;
            double timeHeap3 = 0;
            {
                Vector<int> dist;
                Vector<int> up;

                double start = 0.0;
                double end = 0.0;

                start = clock();

                dijkstraDHeap(dist, up, adj, n, 2, s);

                end = clock();

                timeHeap2 = end - start;
            }

            {
                Vector<int> dist;
                Vector<int> up;

                double start = 0.0;
                double end = 0.0;

                start = clock();

                dijkstraDHeap(dist, up, adj, n, 3, s);

                end = clock();

                timeHeap3 = end - start;
            }
            out << n << ";" << timeHeap2 << ";" << timeHeap3 << "\n";
        }
    }

    {
        std::string name_test = "graphic_2b";
        std::cout << name_test << "\n";
        std::ofstream out(dir + name_test + ".csv");

        out << "N;2-heap;3-heap\n";

        int m = 0;
        int q = 1;
        int r = 1e6;
        int s = 0;
        for (int n = 101; n <= 1e4 + 1; n += 100) {
            m = 1000 * n;
            Vector<Vector<Pair<int, int>>> adj = buildGraph(n, m, q, r);
            double timeHeap2 = 0;
            double timeHeap3 = 0;
            {
                Vector<int> dist;
                Vector<int> up;

                double start = 0.0;
                double end = 0.0;

                start = clock();

                dijkstraDHeap(dist, up, adj, n, 2, s);

                end = clock();

                timeHeap2 = end - start;
            }

            {
                Vector<int> dist;
                Vector<int> up;

                double start = 0.0;
                double end = 0.0;

                start = clock();

                dijkstraDHeap(dist, up, adj, n, 3, s);

                end = clock();

                timeHeap3 = end - start;
            }
            out << n << ";" << timeHeap2 << ";" << timeHeap3 << "\n";
        }
    }

    {
        std::string name_test = "graphic_3";
        std::cout << name_test << "\n";
        std::ofstream out(dir + name_test + ".csv");

        out << "M;2-heap;3-heap\n";

        int n = 1e4+1;
        int q = 1;
        int r = 1e6;
        int s = 0;
        for (int m = 0; m <= 1e7; m += 1e5) {
            Vector<Vector<Pair<int, int>>> adj = buildGraph(n, m, q, r);
            double timeHeap2 = 0;
            double timeHeap3 = 0;
            {
                Vector<int> dist;
                Vector<int> up;

                double start = 0.0;
                double end = 0.0;

                start = clock();

                dijkstraDHeap(dist, up, adj, n, 2, s);

                end = clock();

                timeHeap2 = end - start;
            }

            {
                Vector<int> dist;
                Vector<int> up;

                double start = 0.0;
                double end = 0.0;

                start = clock();

                dijkstraDHeap(dist, up, adj, n, 3, s);

                end = clock();

                timeHeap3 = end - start;
            }
            out << m << ";" << timeHeap2 << ";" << timeHeap3 << "\n";
        }
    }

    {
        std::string name_test = "graphic_4a";
        std::cout << name_test << "\n";
        std::ofstream out(dir + name_test + ".csv");

        out << "r;2-heap;3-heap\n";

        int n = 1e4 + 1;
        int m = n * n;
        int q = 1;
        int s = 0;
        for (int r = 1; r <= 200; ++r) {
            Vector<Vector<Pair<int, int>>> adj = buildGraph(n, m, q, r);
            double timeHeap2 = 0;
            double timeHeap3 = 0;
            {
                Vector<int> dist;
                Vector<int> up;

                double start = 0.0;
                double end = 0.0;

                start = clock();

                dijkstraDHeap(dist, up, adj, n, 2, s);

                end = clock();

                timeHeap2 = end - start;
            }

            {
                Vector<int> dist;
                Vector<int> up;

                double start = 0.0;
                double end = 0.0;

                start = clock();

                dijkstraDHeap(dist, up, adj, n, 3, s);

                end = clock();

                timeHeap3 = end - start;
            }
            out << r << ";" << timeHeap2 << ";" << timeHeap3 << "\n";
        }
    }

    {
        std::string name_test = "graphic_4b";
        std::cout << name_test << "\n";
        std::ofstream out(dir + name_test + ".csv");

        out << "r;2-heap;3-heap\n";

        int n = 1e4 + 1;
        int m = 1000 * n;
        int q = 1;
        int s = 0;
        for (int r = 1; r <= 200; ++r) {
            Vector<Vector<Pair<int, int>>> adj = buildGraph(n, m, q, r);
            double timeHeap2 = 0;
            double timeHeap3 = 0;
            {
                Vector<int> dist;
                Vector<int> up;

                double start = 0.0;
                double end = 0.0;

                start = clock();

                dijkstraDHeap(dist, up, adj, n, 2, s);

                end = clock();

                timeHeap2 = end - start;
            }

            {
                Vector<int> dist;
                Vector<int> up;

                double start = 0.0;
                double end = 0.0;

                start = clock();

                dijkstraDHeap(dist, up, adj, n, 3, s);

                end = clock();

                timeHeap3 = end - start;
            }
            out << r << ";" << timeHeap2 << ";" << timeHeap3 << "\n";
        }
    }
}