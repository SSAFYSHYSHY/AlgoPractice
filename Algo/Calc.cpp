#include "Test.h"
#include <iostream>

using namespace std;

Calc::Calc() {
	name = "Add Calc";
}

string Calc::GetName() {
	return name;
}

int Calc::Add(int a, int b) {
	return a + b;
}

float Calc::Add(float a, float b) {
	return a + b;
}