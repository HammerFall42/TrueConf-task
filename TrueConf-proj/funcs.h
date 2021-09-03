#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <chrono>

#define SIZE 100
#define GEN_LOWER 1
#define GEN_UPPER 9
#define DEL_LOWER 0
#define DEL_UPPER 15

using namespace std;

void fillRandomly(vector <int>& vec, map <int, int>& mp);
void deleteRandomly(vector <int>& vec, map <int, int>& mp);
void syncContainers(vector <int>& vec, map <int, int>& mp);

#endif // FUNCS_H
