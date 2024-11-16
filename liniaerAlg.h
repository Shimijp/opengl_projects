//
// Created by shimo on 16/11/2024.
//

#ifndef LINIAERALG_H
#define LINIAERALG_H
#include <vector>
using namespace std;

using f_vector = std::vector<float>;
using matrix = std::vector<vector<float>>;
f_vector multiply(const f_vector &v1, const matrix &v2);
void printF_vector(const f_vector &v);
#endif //LINIAERALG_H
