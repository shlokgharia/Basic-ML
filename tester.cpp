#include <iostream>
#include "mLearning.h"
using namespace std;
void testbed() {
	program1 a;
    a.createList();
	double answerMin = a.calcMin();
	std::cout << "The minimum for Height is " << answerMin << endl;
	double answerMax = a.calcMax();
	std::cout << "The maximum for Height is " << answerMax << endl;
	double answerMeanM = a.calcMeanM();
    
    double answerMin2 = a.calcMin2();
    std::cout << "The minimum for Handspan is " << answerMin2 << endl;
    double answerMax2 = a.calcMax2();
    std::cout << "The maximum for Handspan is " << answerMax2 << endl;
    
    
	std::cout << "The mean for Male is " << answerMeanM << endl;
	double answerMeanF = a.calcMeanF();
	std::cout << "The mean for Female is " << answerMeanF << endl;
	double answerStDevM = a.calcStDevM();
	std::cout << "The standard deviation for Male is " << answerStDevM << endl;
	double answerStDevF = a.calcStDevF();
	std::cout << "The standard deviation for Female is " << answerStDevF << endl;
	a.calcHistogram();
    std::cout << "The sample size for Males is " << a.calcSampleSizeM() << endl;
    std::cout << "The sample size for Females is " << a.calcSampleSizeF() << endl;
    std::cout << "The Female Histogram Probability for 55 is " << a.calcHistProbF(55.0) << endl;
}


int main() {
	testbed();
	return 0;
}