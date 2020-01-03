#pragma once
#ifndef Person_h
#define Person_h

class Persona {
public:
	double getHeight();
    double getHand();
	char getGender();
    void setHandSpan(double span);
    void setGender(char gender);
	Persona(double, double, char);
	Persona();
private:
	double h;
    double span;
	char g;
};
#endif // !Person_h
