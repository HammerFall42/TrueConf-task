#include "funcs.h"

int main()
{
    vector <int> vec(SIZE);
    map <int, int> mp;

    fillRandomly(vec, mp);
    deleteRandomly(vec, mp);
    syncContainers(vec, mp);

    return 0;
}
