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
    vector <int> num_count(GEN_UPPER - GEN_LOWER + 1);
    fill(num_count.begin(), num_count.end(), 0);

    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        num_count[*it - 1]++;
    }

    for (auto it = mp.begin(); it != mp.end();)
    {
        if (num_count[it->second - GEN_LOWER] > 0)
        {
            num_count[it->second - GEN_LOWER]--;
            it++;
        }
        else
        {
            it = mp.erase(it);
        }
    }

    for (auto it = vec.begin(); it != vec.end();)
    {
        if (num_count[(*it) - GEN_LOWER] > 0)
        {
            num_count[(*it) - GEN_LOWER]--;
            it = vec.erase(it);
        }
        else
        {
            it++;
        }
    }
}
