#include "funcs.h"

void fillRandomly(vector <int>& vec, map <int, int>& mp)
{
    default_random_engine gen;
    uniform_int_distribution<int> dist(GEN_LOWER, GEN_UPPER);
    gen.seed(chrono::system_clock::now().time_since_epoch().count());

    for (int i = 0; i < SIZE; ++i)
    {
        vec[i] = dist(gen);
        mp[i] = dist(gen);
    }
}

void deleteRandomly(vector <int>& vec, map <int, int>& mp)
{
    default_random_engine gen;
    uniform_int_distribution<int> dist(DEL_LOWER, DEL_UPPER);
    gen.seed(chrono::system_clock::now().time_since_epoch().count());

    int vec_del = dist(gen);
    vec.erase(vec.begin(), vec.begin() + vec_del);

    int map_del = dist(gen);
    mp.erase(mp.begin(), next(mp.begin(), map_del));
}

void syncContainers(vector <int>& vec, map <int, int>& mp)
{
    vector <bool> vec_num_flag(GEN_UPPER - GEN_LOWER + 1), mp_num_flag(GEN_UPPER - GEN_LOWER + 1);
    fill(vec_num_flag.begin(), vec_num_flag.end(), false);
    fill(mp_num_flag.begin(), mp_num_flag.end(), false);

    for (auto it = vec.begin(); it != vec.end(); ++it)
        vec_num_flag[(*it) - GEN_LOWER] = true;

    for (auto it = mp.begin(); it != mp.end(); ++it)
        mp_num_flag[it->second - GEN_LOWER] = true;

    for (size_t i = 0; i < GEN_UPPER - GEN_LOWER + 1; ++i)
        vec_num_flag[i] = vec_num_flag[i] && mp_num_flag[i];

    for (auto it = vec.begin(); it != vec.end();)
        if (!vec_num_flag[(*it) - GEN_LOWER])
            it = vec.erase(it);
        else
            ++it;

    for (auto it = mp.begin(); it != mp.end();)
        if (!vec_num_flag[it->second - GEN_LOWER])
            it = mp.erase(it);
        else
            ++it;
}

void printAll(const vector <int>& vec, const map <int, int>& mp)
{
    cout << "Vector: \t";
    for (auto it = vec.begin(); it != vec.end(); ++it)
        cout << (*it) << " ";
    cout << endl << "Map: \t\t";
    for (auto it = mp.begin(); it != mp.end(); ++it)
        cout << it->second << " ";
    cout << endl << endl;
}
