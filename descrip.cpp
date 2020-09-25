#include "Header.h"
using namespace std;


void CIntN::SetNumber(bool m, int* a, int n) {
    this->sign = m;
    this->a = a;
    this->n = n;
}


int& CIntN::operator[](int i) const {
    if (i < 0 || i >= n) {
        printf("Error.Incorrect index\n");
        throw - 1;
    }
    return a[i];
}

CIntN::CIntN(const bool sign, int* a, const int n) {
    this->a = new int[n];
    this->n = n;
    this->sign = sign;
    for (int i = 0; i < n; i++)
        this->a[i] = a[i];
}


CIntN CIntN::operator+(const CIntN& b) {
    int t = 0;
    CIntN r;
    r.a = new int[r.n = n];
    if ((sign == true && b.sign == true) || (sign == false && b.sign == false)) {
        for (int i = r.n - 1; i >= 1; i--) {
            r.a[i] = a[i] + b.a[i];
            if (t == 1) { r.a[i]++; }
            t = 0;
            if (r.a[i] > 9) {
                r.a[i] = r.a[i] % 10;
                t = 1;
            }
            if (sign == true) { 
                r.sign = true; 
            }
            else r.sign = false;
        }
        if (t == 1) {
            r.a[0]++;
        }
        r.a[0] = a[0] + b.a[0];
        if (r.a[0] > 9) {
            throw -3;
        }
        else return r;
    }
    if (sign == true && b.sign == false) {
        if (a[0] > b.a[0]){
            for (int i = r.n - 1; i >= 1; i--) {
                if (t == 1) { 
                    a[i]--;
                }
                t = 0;
                if (a[i] < b.a[i]) {
                    t = 1;
                    a[i] = a[i] + 10;
                }
                r.a[i] = a[i] - b.a[i];

            }
            if (t == 1) { a[0]--; }
            if (a[0] == b.a[0]) {
                throw - 1;
            }
            else{
                r.a[0] = a[0] - b.a[0];
                r.sign = true;
            }
        }
        if (a[0] < b.a[0]) {
            for (int i = r.n - 1; i >= 1; i--) {
                int c = a[i];
                a[i] = b.a[i];
                b.a[i] = c;
                if (t == 1) {
                    a[i]--;
                }
                t = 0;
                if (a[i] < b.a[i]) {
                    t = 1;
                    a[i] = a[i] + 10;
                }
                r.a[i] = a[i] - b.a[i];

            }
            int c = a[0];
            a[0] = b.a[0];
            b.a[0] = c;
            if (t == 1) { a[0]--; }
            if (a[0] == b.a[0]) {
                throw - 1;
            }
            else {
                r.a[0] = a[0] - b.a[0];
                r.sign = false;
            }
        }
        if (a[0] == b.a[0]) {
            throw - 2;
        }
        return r;
    }
    if (sign == false && b.sign == true) {
        if (a[0] > b.a[0]) {
            for (int i = r.n - 1; i >= 1; i--) {
                if (t == 1) {
                    a[i]--;
                }
                t = 0;
                if (a[i] < b.a[i]) {
                    t = 1;
                    a[i] = a[i] + 10;
                }
                r.a[i] = a[i] - b.a[i];

            }
            if (t == 1) { a[0]--; }
            if (a[0] == b.a[0]) {
                throw - 1;
            }
            else {
                r.a[0] = a[0] - b.a[0];
                r.sign = false;
            }
        }
        if (a[0] < b.a[0]) {
            for (int i = r.n - 1; i >= 1; i--) {
                int c = a[i];
                a[i] = b.a[i];
                b.a[i] = c;
                if (t == 1) {
                    a[i]--;
                }
                t = 0;
                if (a[i] < b.a[i]) {
                    t = 1;
                    a[i] = a[i] + 10;
                }
                r.a[i] = a[i] - b.a[i];

            }
            int c = a[0];
            a[0] = b.a[0];
            b.a[0] = c;
            if (t == 1) { a[0]--; }
            if (a[0] == b.a[0]) {
                throw - 1;
            }
            else {
                r.a[0] = a[0] - b.a[0];
                r.sign = true;
            }
        }
        if (a[0] == b.a[0]) {
            throw - 2;
        }
        return r;
    }
    delete[] r.a;
}

CIntN CIntN::operator-(const CIntN& b) {
    int t = 0;
    CIntN r;
    r.a = new int[r.n = n];
    if ((sign == true && b.sign == false) || (sign == false && b.sign == true)) {
        for (int i = r.n - 1; i >= 1; i--) {
            r.a[i] = a[i] + b.a[i];
            if (t == 1) { r.a[i]++; }
            t = 0;
            if (r.a[i] > 9) {
                r.a[i] = r.a[i] % 10;
                t = 1;
            }
            if (sign == true) {
                r.sign = true;
            }
            else r.sign = false;
        }
        if (t == 1) {
            r.a[0]++;
        }
        r.a[0] = a[0] + b.a[0];
        if (r.a[0] > 9) {
            throw - 3;
        }
        else return r;
    }
    if (sign == true && b.sign == true) {
        if (a[0] > b.a[0]) {
            for (int i = r.n - 1; i >= 1; i--) {
                if (t == 1) {
                    a[i]--;
                }
                t = 0;
                if (a[i] < b.a[i]) {
                    t = 1;
                    a[i] = a[i] + 10; 
                }
                r.a[i] = a[i] - b.a[i];

            }
            if (t == 1) { a[0]--; }
            if (a[0] == b.a[0]) {
                throw - 1;
            }
            else {
                r.a[0] = a[0] - b.a[0];
                r.sign = true;
            }
        }
        if (a[0] < b.a[0]) {
            for (int i = r.n - 1; i >= 1; i--) {
                int c = a[i];
                a[i] = b.a[i];
                b.a[i] = c;
                if (t == 1) {
                    a[i]--;
                }
                t = 0;
                if (a[i] < b.a[i]) {
                    t = 1;
                    a[i] = a[i] + 10;
                }
                r.a[i] = a[i] - b.a[i];

            }
            int c = a[0];
            a[0] = b.a[0];
            b.a[0] = c;
            if (t == 1) { a[0]--; }
            if (a[0] == b.a[0]) {
                throw - 1;
            }
            else {
                r.a[0] = a[0] - b.a[0];
                r.sign = false;
            }
        }
        return r;
    }
    if (sign == false && b.sign == false) {
        if (a[0] > b.a[0]) {
            for (int i = r.n - 1; i >= 1; i--) {
                if (t == 1) {
                    a[i]--;
                }
                t = 0;
                if (a[i] < b.a[i]) {
                    t = 1;
                    a[i] = a[i] + 10; 
                }
                r.a[i] = a[i] - b.a[i];

            }
            if (t == 1) { a[0]--; }
            if (a[0] == b.a[0]) {
                throw - 1;
            }
            else {
                r.a[0] = a[0] - b.a[0];
                r.sign = false;
            }
        }
        if (a[0] < b.a[0]) {
            for (int i = r.n - 1; i >= 1; i--) {
                int c = a[i];
                a[i] = b.a[i];
                b.a[i] = c;
                if (t == 1) {
                    a[i]--;
                }
                t = 0;
                if (a[i] < b.a[i]) {
                    t = 1;
                    a[i] = a[i] + 10;
                }
                r.a[i] = a[i] - b.a[i];

            }
            int c = a[0];
            a[0] = b.a[0];
            b.a[0] = c;
            if (t == 1) { a[0]--; }
            if (a[0] == b.a[0]) {
                throw - 1;
            }
            else {
                r.a[0] = a[0] - b.a[0];
                r.sign = true;
            }
        }
        if (a[0] == b.a[0]) {
            throw - 2;
        }
        return r;
    }
    delete[] r.a;
}

void CIntN::GetNumber()const {
    if (sign == true){}
    else printf("-");
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
    }
    printf("\n");
}