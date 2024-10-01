#pragma once

#include "Vector.h"

template <typename T>
class d_heap {
    int d;
    int n;
    Vector<T> mem;
    Vector<int> index;

    int firstChild(int i) {
        int k = i * d + 1;
        if (k >= n) return 0;
        return k;
    }

    int lastChild(int i) {
        int k = firstChild(i);
        if (k == 0) return 0;
        return myMin(k + d - 1, n);
    }

    int minChild(int i) {
        int kf = firstChild(i);
        if (kf == 0) return i;
        int kl = lastChild(i);
        T min_mem = mem[kf];
        int ind = kf;
        for (int j = kf + 1; j < kl; ++j) {
            if (mem[j] < min_mem) {
                min_mem = mem[j];
                ind = j;
            }
        }
        return ind;
    }

    int father(int i) {
        return (i - 1) / d;
    }

public:
    d_heap(int _d) {
        d = _d;
        n = 0;
        Vector<T> mem;
        Vector<int> index;
    }

    void siftDown(int i) {
        T mem0 = mem[i];
        int c = minChild(i);
        while (c != i && mem0 > mem[c]) {
            mem[i] = mem[c];
            index[mem[i].first] = i;
            i = c;
            c = minChild(i);
        }
        mem[i] = mem0;
        index[mem[i].first] = i;
    }

    void siftUp(int i) {
        T mem0 = mem[i];
        int p = father(i);
        while (i != 0 && mem[p] > mem0) {
            mem[i] = mem[p];
            index[mem[i].first] = i;
            i = p;
            p = father(i);
        }
        mem[i] = mem0;
        index[mem[i].first] = i;
    }

    void removeMin(T& mem1) {
        mem1 = mem[0];
        mem[0] = mem[n - 1];
        mem.pop_back();
        --n;
        if (n > 0) {
            siftDown(0);
        }
    }

    void insert(T& _mem, int _ind) {
        mem.push_back(_mem);
        index.push_back(_ind);
        ++n;
        siftUp(n - 1);
    }

    int getSize() {
        return n;
    }

    T& operator[](const int i) {
        return mem[i];
    }

    int getIndex(int i) {
        return index[i];
    }

    void showDHeap() {
        cout << "\nname: ";
        for (int i = 0; i < n; ++i) {
            cout << mem[i].first << " ";
        }
        cout << "\nkey: ";
        for (int i = 0; i < n; ++i) {
            cout << mem[i].second << " ";
        }
        cout << "\nindex: ";
        for (int i = 0; i < index.getSize(); ++i) {
            cout << index[i] << " ";
        }
        cout << "\n";
    }
};