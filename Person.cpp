#include "Person.h"

Persona::Persona() {
	h = 0;
	g = 'M';
}

Persona::Persona(double height, double handspan, char gender) {
	h = height;
    span = handspan;
	g = gender;
}
double Persona::getHeight() {
	return h;
}

double Persona::getHand() {
    return span;
}

char Persona::getGender() {
	return g;
}

void Persona::setHandSpan(double handspan)
{
    span = handspan;
}

void Persona::setGender(char gender)
{
    g = gender;
}
