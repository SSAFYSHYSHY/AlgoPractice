#pragma once

//Unreal CH2 Tuto
#include <iostream>
using namespace std;

class Calc {
protected:
	string name;
public:
	Calc();

	string GetName();

	int Add(int a, int b);
	float Add(float a, float b);
};