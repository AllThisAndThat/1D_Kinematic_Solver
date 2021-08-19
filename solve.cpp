#include "solve.h"

using namespace std;

void Solve::find() {
    find_a();
    find_v_i();
    find_v_f();
    find_d();
    find_t();
}

void Solve::find_a() {
    if (a_set) {
        return;
    }
    else if (v_i_set && v_f_set && d_set) {
        a = (pow(v_f, 2) - pow(v_i, 2)) / (2 * d);
    }
    else if (v_i_set && v_f_set && t_set) {
        a = (v_f - v_i) / t;
    }
    else if (v_i_set && d_set && t_set) {
        a = 2 * ((d / pow(t, 2)) - ((2 * v_i) / t)); 
    }
    else if (v_f_set && d_set && t_set) {
        a = 2 * ((v_f / t) - (d / pow(t, 2)));
    }
}

void Solve::find_v_i() {
    if (v_i_set) {
        return;
    }
    else if (a_set && v_f_set && d_set) {
        v_i = sqrt(pow(v_f, 2) - (2 * a * d)); // Investigate Me
    }
    else if (a_set && v_f_set && t_set) {
        v_i = v_f - (a * t);
    }
    else if (a_set && d_set && t_set) {
        v_i = (d / t) - (0.5 * a * t);
    }
    else if (v_f_set && d_set && t_set) {
        v_i = ((2 * d) / t) - v_f;
    }
}

void Solve::find_v_f() {
    if (v_f_set) {
        return;
    }
    else if (a_set && v_i_set && d_set) {
        v_f = sqrt(pow(v_i, 2) + (2 * a * d)); // Investigate Me
    }
    else if (a_set && v_i_set && t_set) {
        v_f = v_i + (a * t);
    }
    else if (a_set && d_set && t_set) {
        v_f = (d / t) + (0.5 * a * t);
    }
    else if (v_i_set && d_set && t_set) {
        v_f = ((2 * d) / t) - v_i;
    }
}

void Solve::find_d() {
    if (d_set) {
        return;
    }
    else if (a_set && v_i_set && v_f_set) {
        d = (pow(v_f, 2) - pow(v_i, 2)) / (2 * a);
    }
    else if (a_set && v_i_set && t_set) {
        d = (v_i * t) + (0.5 * a * pow(t, 2));
    }
    else if (a_set && v_f_set && t_set){
        d = (v_f * t) - (0.5 * a * pow(t, 2));
    }
    else if (v_i_set && v_f_set && t_set) {
        d = ((v_i + v_f) / 2) * t;
    }
}

void Solve::find_t() {
    if (t_set) {
        return;
    }
    else if (a_set && v_i_set && v_f_set) {
        t = (v_f - v_i) / a;
    }
    else if (a_set && v_i_set && d_set) {
        t = (-v_i + sqrt(pow(v_i, 2) + (2 * a * d))) / a; // Investigate Me
    }
    else if (a_set && v_f_set && d_set){
        t = (v_f + sqrt(pow(v_f, 2) - (2 * a * d))) / a; // Investigate Me
    }
    else if (v_i_set && v_f_set && d_set) {
        t = d / (2 * (v_i + v_f));
    }
    return;
}

void Solve::print_all() {
    // Horizontal Bar
    for (int i = 0; i < 30; i ++) {
        cout << "-";
    }
    cout << endl;

    cout << "Knowns:" << endl;
    if (a_set) {
        cout << "a: " << a << " m/s^2" << endl;
    }
    if (t_set) {
        cout << "t: " << t << " s" << endl;
    }
    if (v_i_set) {
        cout << "v_i: " << v_i << " m/s" << endl;
    }
    if (v_f_set) {
        cout << "v_f: " << v_f << " m/s" << endl;
    }
    if (d_set) {
        cout << "d: " << d << " m" << endl;
    }

    cout << endl;

    cout << "Unknowns:" << endl;
    if (!a_set) {
        cout << "a: " << a << " m/s^2" << endl;
    }
    if (!t_set) {
        cout << "t: " << t << " s" << endl;
    }
    if (!v_i_set) {
        cout << "v_i: " << v_i << " m/s" << endl;
    }
    if (!v_f_set) {
        cout << "v_f: " << v_f << " m/s" << endl;
    } 
    if (!d_set) {
        cout << "d: " << d << " m" << endl;
    }
}