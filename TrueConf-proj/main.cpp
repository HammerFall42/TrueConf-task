#include "funcs.h"

int main()
{
    vector <int> vec(SIZE);
    map <int, int> mp;

    fillRandomly(vec, mp);
    cout << "After filling" << endl;
    printAll(vec, mp);
    deleteRandomly(vec, mp);
    cout << "After deleting" << endl;
    printAll(vec, mp);
    syncContainers(vec, mp);
    cout << "After synchronizing" << endl;
    printAll(vec, mp);

    return 0;
}
