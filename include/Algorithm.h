#pragma once

#include <iostream>
#include <random>
#include "Vector.h"
#include "Pair.h"
#include "Dheap.h"

template <typename T>
void mySwap(T& a, T& b) {
    T x = a;
    a = b;
    b = x;
}

template <typename T>
T myMin(T& a, T& b) {
    if (a < b) {
        return a;
    }
    return b;
}

template <typename T>
T myMin(T&& a, T&& b) {
    if (a < b) {
        return a;
    }
    return b;
}

template <typename T>
T myMin(T& a, T&& b) {
    if (a < b) {
        return a;
    }
    return b;
}

template <typename T>
T myMin(T&& a, T& b) {
    if (a < b) {
        return a;
    }
    return b;
}

Vector<Vector<Pair<int, int>>> buildGraph(int n, int m) {
    int k = n * (n - 1) / 2;
    m = myMin(k, m);
    Vector<Vector<Pair<int, int>>> a(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n && cnt < m; ++j, ++cnt) {
            int l = rand() % 10 + 1;
            a[i].push_back(Pair<int, int>(j, l));
            a[j].push_back(Pair<int, int>(i, l));
        }
    }
    return a;
}

template <typename T>
d_heap<T> buildDHeap(Vector<T>& mem, Vector<int>& index, int d) {
    d_heap<Pair<int, int>> dh(d);
    for (int i = 0; i < mem.getSize(); ++i) {
        dh.insert(mem[i], index[i]);
    }
    return dh;
}

void showGraph(Vector<Vector<Pair<int, int>>>& graph) {
    for (int i = 0; i < graph.getSize(); ++i) {
        std::cout << i << ": ";
        for (int j = 0; j < graph[i].getSize(); ++j) {
            std::cout << "\t(" << graph[i][j].first << ", " << graph[i][j].second << ")\n";
        }
        std::cout << "\n";
    }
}

void dijkstraDHeap(Vector<int>& dist, Vector<int>& up,
    Vector<Vector<Pair<int, int>>>& adj, int n, int d, int s) {

    dist = Vector<int>(n, INT_MAX);
    up = Vector<int>(n, -1);
    Vector<int> index(n);
    Vector<Pair<int, int>> mem(n);
    for (int i = 0; i < n; ++i) {
        index[i] = i;
        mem[i] = Pair<int, int>(i, INT_MAX);
    }
    mem[s].second = 0;
    d_heap<Pair<int, int>> dh = buildDHeap(mem, index, d);
    while (dh.getSize() > 0) {
        Pair<int, int> mem1;
        dh.removeMin(mem1);
        int i = mem1.first;
        dist[i] = mem1.second;
        for (int l = 0; l < adj[i].getSize(); ++l) {
            Pair<int, int> p = adj[i][l];
            int j = p.first;
            if (j == s) continue;
            int jq = dh.getIndex(j);
            if (/*dist[j] == INT_MAX &&*/ dh[jq].second > dist[i] + p.second) {
                dh[jq].second = dist[i] + p.second;
                dh.siftUp(jq);
                up[j] = i;
            }
        }
    }
}