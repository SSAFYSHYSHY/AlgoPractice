#pragma once

//Unreal CH2 Tuto

#include <iostream>

using namespace std;

class Calc {
public:
	float Add(float a, float b);
	float Sub(float a, float b); 

private:
	void OutPut(float, string, float, float);
};