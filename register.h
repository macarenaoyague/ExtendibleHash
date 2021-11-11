#include "parsing.cpp"

const int fb = 7;

struct Register {
    int rank;
    void setData() {
        std::cout << "Rank:\n";
        std::cin >> rank;
    }
    void show() {
        std::cout << '\n' << rank << '\n';
    }
};

struct index_hash {
    int key;
    int bucket_position;
    int d;
    void set(int _key, int _position, int _d) {
        key = _key;
        bucket_position = _position;
        d = _d;
    }
};

struct bucket_university {
    University registros[fb];
    int cant;
    int next;
    void set(int _cant, int _next) {
        cant = _cant;
        next = _next;
    }
    bucket_university() = default;
};

struct bucket_population {
    Population registros[fb];
    int cant;
    int next;
    void set(int _cant, int _next) {
        cant = _cant;
        next = _next;
    }
    bucket_population() = default;
};



struct bucket_reg {
    Register registros[fb];
    int cant;
    int next;
    void set(int _cant, int _next) {
        cant = _cant;
        next = _next;
    }
};
