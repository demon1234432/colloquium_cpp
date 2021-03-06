// Copyright 2015 Comrads 4371
#ifndef MOD_NN_N_CPP
#define MOD_NN_N_CPP

#include <stdexcept>

#include "../../structs/struct.h"
#include "./DIV_NN_N.cpp"
#include "./MUL_NN_N.cpp"
#include "./SUB_NN_N.cpp"
#include "./NZER_N_B.cpp"

natural MOD_NN_N(const natural& a, const natural& b) {
    if (NZER_N_B(b))
        throw std::invalid_argument("Your divider is equal to zero");

    natural divident = a;
    natural divider = b;
    natural fact = DIV_NN_N(divident, divider);
    divider = MUL_NN_N(divider, fact);
    natural res = SUB_NN_N(divident, divider);

    return natural(res);
}

natural natural::operator%(const natural& other) {
    return MOD_NN_N(*this, other);
}

#endif  // MOD_NN_N_CPP
