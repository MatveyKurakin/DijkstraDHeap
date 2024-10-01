#pragma once

template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair() {
        first = T1();
        second = T2();
    }

    Pair(T1 _first, T2 _second) {
        first = _first;
        second = _second;
    }

    Pair(const Pair& other) {
        first = other.first;
        second = other.second;
    }

    Pair& operator=(const Pair& other) {
        if (this != &other) {
            first = other.first;
            second = other.second;
        }
        return *this;
    }

    bool operator<(Pair& pr) const {
        if (second < pr.second)
            return true;
        return false;
    }

    bool operator>(Pair& pr) const {
        if (second > pr.second)
            return true;
        return false;
    }

    bool operator<=(Pair& pr) const {
        if (second <= pr.second)
            return true;
        return false;
    }

    bool operator>=(Pair& pr) const {
        if (second >= pr.second)
            return true;
        return false;
    }

};