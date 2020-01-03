#pragma once
#ifndef mLearning_h
#define mLearning_h
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdlib.h>
using namespace std;
class program1 {
public:
    void createList();
    void create50List();
	double calcMin();//Minimum
	double calcMax();//Maximum
    double calcMin2();//Minimum
    double calcMax2();//Maximum
	double calcMeanM();//Mean of Males
	double calcMeanF();//Mean of Females
	double calcStDevM();//Standard Deviation of Males
	double calcStDevF();//Standard Deviation of Females
	void calcHistogram();//Histogram
	int BF(double k);//Used to calculate Histogram
	double calcHistProbM(double qInput);
    double calcHistProbF(double qInput);
    int calcSampleSizeM();
    int calcSampleSizeF();
	double calcBayProbM(double qInput);//NOT DONE YET
    double calcBayProbF(double qInput);//NOT DONE YET
private:
	double maxD = 0;
	double minD = 0;
    double hBM[32] = { 0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,0.0 };
    double hBF[32] = { 0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,
        0.0,0.0,0.0,0.0,0.0,0.0,0.0 };
};


#endif // !mLearning_h
