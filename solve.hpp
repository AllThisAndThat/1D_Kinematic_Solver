#ifndef SOLVE_H
#define SOLVE_H

#include <cmath>
#include <iostream>
#include <stdlib.h>

class Solve {
    private:
        double a;
        double v_i;
        double v_f;
        double d;
        double t;

        bool a_set = false;
        bool v_i_set = false;
        bool v_f_set = false;
        bool d_set = false;
        bool t_set = false;

    public:
        void set_a (double a) {this->a = a; a_set = true;}
        void set_v_i (double v_i) {this->v_i = v_i; v_i_set = true;}
        void set_v_f (double v_f) {this->v_f = v_f; v_f_set = true;}
        void set_d (double d) {this->d = d; d_set = true;}
        void set_t (double t) {this->t = t; t_set = true;}

        double get_a () {return a;}
        double get_v_i () {return v_i;}
        double get_v_f () {return v_f;}
        double get_d () {return d;}
        double get_t () {return t;}

        void find();

        void find_a();
        void find_v_f();
        void find_v_i();
        void find_d();
        void find_t();

        void print_all();
};

#endif