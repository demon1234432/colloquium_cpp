// Copyright 2015 Belkin Dmitriy
#ifndef STRUCT_H
#define STRUCT_H

#include <vector>
#include <iterator>
#include <string>
#include <initializer_list>

#include "digit.h"
#include "ordinal.h"

// #яХочуКлассы #нужноБольшеИнкапсуляции
// Натуральное число
struct natural {
    natural(): natural({ _0 }) { }  // инициализация нулем
    natural(const natural& number) {
        this->digits = number.digits;  // vector copy constructor
    }

    // Конструктор из списка цифр в нормальном порядке: { _3, _4, _0 } <===> 340
    natural(std::initializer_list<digit> digits) {
        std::vector<digit> tmp(digits);

        // Костыль с reverse iterator
        auto it = tmp.rbegin();
        while (it != tmp.rend()) {
            this->digits.push_back(*it);
            it++;
        }
    }

    // Контруктор из строки "42" <===> 42
    natural(const std::string &input) {
      auto it = input.rbegin();
      while (it != input.rend()) {
        if (('0' <= *it) && (*it <= '9')) {
            this->digits.push_back(static_cast<digit>(*it - '0'));
            it++;
        } else {
            // if (*it == std::string::npos) return;
            throw;
              // TODO(timecatler): exception
        }
      }
    }

    // Уничтожитель незначащих нулей
    void reduce() {
        while ((digits.back() == _0) && (digits.size() != 0)) {
            digits.pop_back();
        }
    }

    void orderShift(const unsigned &orderCount) {
        unsigned order = orderCount;
        while (order --> 0) {
            digits.insert(digits.begin(), _0);
        }
    }

    // Количество значащих разрядов в числе
    // Выделить в отдельную переменную?
    int order() const {
        int k = digits.size();
        while (digits[k - 1] == _0 && k > 0) { k--; }
        return k;
    }

    natural& operator= (const natural& other) {
        // TODO: проверка самоприсвоения
        digits = other.digits;
        return *this;
    }

    ~natural() {
        digits.clear();
        // delete digits;
    }

    // TODO: переопределить операторы
    digit& operator[](const int& digitInd) {
        if (digitInd >= order()) {
            int k = order();
            while(digitInd >= k) {
                digits.push_back( _0 );
                k++;
            }
        }
        return digits[digitInd];
    }

    natural operator+(const natural& other);
    natural operator-(const natural& other);

    void operator++( int );
    bool operator==(const natural& other);

    static const natural one = natural({ _1 });
    static const natural zero = natural({ _0 });

 private:
    // Массив цифр от младших разрядов к старшим
    // Число 9426 будет представленно как { 6, 2, 4, 9 }
    std::vector<digit> digits;
};

// Целое число
struct integer {
    bool sign;
    natural module;
};

// Рациональное число
struct fraction {
    //Числитель дроби
    integer numerator;
    //Знаменатель дроби
    natural denominator;
};

// Многочлен
struct polynom {
    polynom(): polynom({ _0 }) { }
    polynom(const polynom& other) {
        this->coefficients = other.coefficients;
    }

    polynom(std::initializer_list<fraction> coefficients) {
        std::vector<fraction> tmp(coefficients);

        auto it = tmp.rbegin();
        while (it != tmp.rend()) {
            this->coefficients.push_back(*it);
            it++;
        }
    }

    void reduce() {
        while ((coefficients.back() == _0) && (coefficients.size() != 0)) {
            coefficients.pop_back();
        }
    }

    // Степень многочлена
    int degree() const {
        int k = coefficients.size();
        while (coefficients[k - 1] == _0 && k > 0) { k--; }
        return k;
    }

    void degreeShift(const unsigned &degreeCount) {
        unsigned order = degreeCount;
        while (order --> 0) {
            coefficients.insert(coefficients.begin(), _0);
        }
    }

    polynom& operator= (const polynom& other) {
        // TODO: проверка самоприсвоения
        coefficients = other.coefficients;
        return *this;
    }

    ~polynom() {
        coefficients.clear();
    }

    digit& operator[](const int& coeffInd) {
        if (coeffInd >= degree()) {
            int k = degree();
            while(coeffInd >= k) {
                coefficients.push_back( _0 );
                k++;
            }
        }
        return coefficients[coeffInd];
    }

 private:
    // Коэффициенты многочлена в порядке увеличения степени
    // 18x^3 + 4x^2 + 3 <==> { 3, 0, 4, 18 }
    std::vector<fraction> coefficients;

};

#endif  // STRUCT_H
