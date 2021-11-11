#include "extendible_hash.cpp"
#include <chrono>

template <class T, class bucket>
void test_insert(vector <T> elements, string index_filename, string data_filename) {
    // fb settear a 7
    int D = 5;
    extendible_hash<T, bucket> hash (D, index_filename, data_filename);
    vector<float> write_cant;
    vector<float> read_cant;

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    vector<double> time_milli;

    for (T e : elements) {
        hash.write_cant = hash.read_cant = 0;

        auto t1 = high_resolution_clock::now();

        hash.insert_register(e);

        auto t2 = high_resolution_clock::now();
        duration<double, std::milli> ms_double = t2 - t1;
        time_milli.push_back(ms_double.count());
        write_cant.push_back(hash.write_cant);
        read_cant.push_back(hash.read_cant);
    }

    float write_avg = 0, read_avg = 0;
    double time_avg = 0;
    float cant = write_cant.size();
    for (int i = 0; i < cant; i++) {
        write_avg += write_cant[i];
        read_avg += read_cant[i];
        time_avg += time_milli[i];
    }

    write_avg /= cant;
    read_avg /= cant;
    time_avg /= cant;

    cout << "Promedio de escritura en inserciones: " << write_avg << '\n';
    cout << "Promedio de lectura en inserciones: " << read_avg << '\n';
    cout << "Promedio de tiempo en inserciones: " << time_avg << '\n';

    //hash.print_all();
}

template <class T, class bucket>
void test_search(vector <T> elements, string index_filename, string data_filename) {
    // fb settear a 7
    int D = 5;
    extendible_hash<T, bucket> hash (D, index_filename, data_filename);
    for (T e : elements) 
        hash.insert_register(e);

    vector<float> read_cant;
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    vector<double> time_milli;
    
    T element;
    int mini = 0;
    for (T e : elements) {
        hash.read_cant = 0;
        auto t1 = high_resolution_clock::now();
        hash.search_register(e.rank, element);
        auto t2 = high_resolution_clock::now();
        duration<double, std::milli> ms_double = t2 - t1;
        if (mini < hash.read_cant) 
            mini = hash.read_cant;
        time_milli.push_back(ms_double.count());
        read_cant.push_back(hash.read_cant);
    }
    cout << mini << endl;
    float read_avg = 0;
    double time_avg = 0;
    float cant_populations = read_cant.size();
    for (int i = 0; i < cant_populations; i++) {
        read_avg += read_cant[i];
        time_avg += time_milli[i];
    }

    read_avg /= cant_populations;
    time_avg /= cant_populations;

    cout << "Promedio de lectura en inserciones: " << read_avg << '\n';
    cout << "Promedio de tiempo en inserciones: " << time_avg << '\n';

    //hash.print_all();
}


int main(){

    /* 
        CONSIDERACIONES: los archivos deben estar creados 
        - vacíos
        - con datos y hash ya inicializado
    */

    int D = 5;

    vector <Population> populations = read_populations("files/population.csv");
    extendible_hash<Population, bucket_population> hash_pop (D, "files/index_popu.dat", "files/data_popu.dat");
    //for (Population e : populations) 
     //   hash_pop.insert_register(e);
    //hash.search_register().show();

    hash_pop.delete_register(100);
    hash_pop.print_all();
    
    
    vector <University> universities = read_universities("files/rank-univ.csv");
    extendible_hash<University, bucket_university> hash_uni (D, "files/index_uni.dat", "files/data_uni.dat");
    //for (University e : universities) 
      //  hash_uni.insert_register(e);
    //hash_uni.print_all();
    //University uni;
    //hash_uni.search_register(124, uni);
    //uni.show();

    return 0;
}