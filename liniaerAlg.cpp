//
// Created by shimo on 16/11/2024.
//

#include "liniaerAlg.h"

#include <iostream>


// Function to multiply a vector by a matrix
f_vector multiply(const f_vector &v1, const matrix &v2) {
    f_vector res;
    res.resize(v1.size());
    for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v2.size(); j++) {
            res.at(i) += v2.at(j).at(i) * v1.at(j);
        }
    }
    return res;
}
void printF_vector(const f_vector &v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}