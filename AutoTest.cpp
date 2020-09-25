#include "Header.h"

using namespace std;

void AutoTest() {
    bool m,n;
    CIntN A;
    CIntN B;
    int* a = new int[3];
    m = true;
    a[0] = 2;
    a[1] = 2;
    a[2] = 0;
    A.SetNumber(m, a, 3);
    int* b = new int[3];
    n = false;
    b[0] = 1;
    b[1] = 0;
    b[2] = 3;
    B.SetNumber(n, b, 3);
    CIntN C = A + B;
    C.GetNumber();
    CIntN D = A - B;
    D.GetNumber();
    if (C.A()[0] == 1 && C.A()[1] == 1 && C.A()[2] == 7  && C.S() == true && D.A()[0] == 3 && D.A()[1] == 2 && D.A()[2] == 3 && D.S() == true) {
        cout << "AutoTest passed..." << endl;
    }
    else {
        cout << "AutoTest falled..." << endl;
    }
}

