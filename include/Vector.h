#pragma once

template<typename T>
class Vector {
    int size;
    int mem_size;
    T* mem;
public:
    Vector() {
        size = 0;
        mem_size = 0;
        mem = new T[0];
    }

    Vector(const int n) {
        size = n;
        mem_size = n;
        mem = new T[n];
        for (int i = 0; i < size; ++i) {
            mem[i] = T();
        }
    }

    Vector(const int n, const T& a) {
        size = n;
        mem_size = n;
        mem = new T[n];
        std::fill(mem, mem + n, a);
    }

    Vector(const Vector& other) {
        size = other.size;
        mem_size = other.mem_size;

        mem = new T[mem_size];
        for (int i = 0; i < size; ++i) {
            mem[i] = other.mem[i];
        }
    }

    ~Vector() {
        delete[] mem;
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            size = other.size;
            mem_size = other.mem_size;
            delete[] mem;

            mem = new T[mem_size];
            for (int i = 0; i < size; ++i) {
                mem[i] = other.mem[i];
            }
        }
        return *this;
    }

    void push_back(const T& a) {
        if (size == 0) {
            size = 1;
            mem_size = 1;
            mem = new T[size];
            mem[0] = a;
            return;
        }
        if (size < mem_size) {
            mem[size] = a;
            ++size;
        }
        else {
            mem_size += size;
            T* new_mem = new T[mem_size];
            for (int i = 0; i < size; ++i) {
                new_mem[i] = mem[i];
            }
            delete[] mem;
            mem = new_mem;
            mem[size] = a;
            ++size;
        }
    }

    bool pop_back() {
        if (size > 0) {
            --size;
            if (size == mem_size - size) {
                mem_size -= size;
                T* new_mem = new T[mem_size];
                for (int i = 0; i < size; ++i) {
                    new_mem[i] = mem[i];
                }
                delete[] mem;
                mem = new_mem;
            }
            return true;
        }
        return false;
    }

    void clear() {
        size = 0;
        mem_size = 0;
        delete[] mem;
        mem = new T[0];
    }

    T& operator[](const int i) const {
        if (i >= size)
            return mem[size - 1];
        if (i < 0)
            return mem[0];
        return mem[i];
    }

    void showMem() {
        cout << "Mem: ";
        for (int i = 0; i < mem_size; ++i) {
            cout << mem[i] << " ";
        }
        cout << "\n";
        cout << "Size: " << size << "\nCapacity: " << mem_size << "\n";
    }

    int getCapacity() const {
        return mem_size;
    }

    int getSize() const {
        return size;
    }

};