/*
*   Author: Lucas Hudson
*   Date: Summer 2021
*   File: main.cpp
*   Description: Handle and test physics functions to practice C++.
*/

#include <iostream>
#include "solve.h"

using namespace std;

int main() {
    Solve system = Solve();

    system.set_a(9.81);
    system.set_d(10);
    system.set_v_i(5);

    system.find();

    system.print_all();
}

