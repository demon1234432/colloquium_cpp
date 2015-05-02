// Copyright 2015 Comrads 4371
#ifndef MOD_NN_N_CPP
#define MOD_NN_N_CPP

#include <stdexcept>

#include "../../structs/struct.h"
#include "./DIV_NN_N.cpp"
#include "./MUL_NN_N.cpp"
#include "./SUB_NN_N.cpp"

natural MOD_NN_N(const natural& a, const natural& b) {
    if (b == _0) throw std::invalid_argument("Your divider is equal to zero");

    natural res;
    natural divident = a;
    natural divider = b;
    natural fact;

    fact = DIV_NN_N(divident, divider);
    divider = MUL_NN_N(divider, fact);
    res = SUB_NN_N(divident, divider);

    return res;
}

#endif  // MOD_NN_N_CPP
