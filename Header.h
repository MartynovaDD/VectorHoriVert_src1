#pragma once
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <fstream>
void AutoTest();
void AutoTest();


class CIntN {
	int n;
	int* a;
	bool sign;
public:
	int* A()const {
		return a;
	}
	int lenght()const {
		return n;
	}
	int S() {
		return sign;
	}
	CIntN() { 
		SetZero(); 
	}
	~CIntN() { 
		Clean(); 
	}
	CIntN(const CIntN& b) { 
		CopyOnly(b);
	}
	CIntN& operator=(const CIntN& b) { 
		if (this != &b) { 
			Clean(); 
			CopyOnly(b); 
		}
		return *this; 
	}
	void SetNumber(bool m, int* a, int n);
	void Clean() { 
		delete[] a; 
		SetZero(); 
	}
	void SetZero() { 
		a = NULL; 
		sign = NULL; 
		n = 0; 
	}
	void CopyOnly(const CIntN& b) { 
		n = b.n; 
		sign = b.sign;
		a = new int[n];
		for (int i = 0; i < n; i++) 
			a[i] = b[i]; 
	}
	CIntN(const bool sign, int* a, const int n);
	CIntN operator+(const CIntN& b);
	CIntN operator-(const CIntN& c);
	int& operator[](int i) const;
	void GetNumber()const;
};