#include "mLearning.h"
#include "Person.h"


//const double E = M_E;
const double PI = M_PI;
std::vector<Persona> pList;
std::vector<Persona>::iterator it;
int counter = 0;

void program1::createList()
{
    it = pList.begin();
    string line;
    ifstream listFile;
    listFile.open("/Users/shlokgharia/Documents/C++ Projects/Assignment2_ML/Assignment2_ML/listFile2.txt");
    //if(listFile.is_open())
    //{
        //This while loop creates people in the pList and sets the height according to the Height from the listFile.txt (It also initializes gender as Male)
        while (getline(listFile, line)) {
            if (line == " ") {
                break;
            }
            else
            {
            it = pList.insert(it,Persona(atof(line.c_str()), 0.0, 'M'));
            counter++;
            }
        }
    //This starts setting the handspan for the people in the list
        it = pList.begin();
        for (int i = counter; i >= 0; i--) {
            getline(listFile, line);
            if (line == " ") {
                break;
            }
            else{
                pList[i].setHandSpan(atof(line.c_str()));
            }
        
        }
    //This starts setting the gender for the people in the list
        it = pList.begin();
        for (int i = counter; i >= 0; i--) {
            getline(listFile, line);
            if (line == "Male") {
                pList[i].setGender('M');
            }
            else if (line == "Female") {
                pList[i].setGender('F');
            }
               
        }
    //}
}
    
void program1::create50List()
{
    it = pList.begin();
    string line;
    ifstream listFile;
    listFile.open("/Users/shlokgharia/Documents/C++ Projects/mlassignment1/listFile.txt");
    //if(listFile.is_open())
    //{
    //This while loop creates people in the pList and sets the height according to the Height from the listFile.txt (It also initializes gender as Male)
    while (getline(listFile, line)) {
        if (counter==50) {
            break;
        }
        else
        {
            it = pList.insert(it,Persona(atof(line.c_str()), 0.0, 'M'));
            counter++;
        }
    }
    //This starts setting the gender for the people in the list
    it = pList.begin();
    while (getline(listFile, line)) {
        if(line == " ") { break;}
    }
    
    for (int i = counter; i >= 0; i--) {
        getline(listFile, line);
        if (line == "Male") {
            pList[i].setGender('M');
        }
        else if (line == "Female") {
            pList[i].setGender('F');
        }
        
    }
    //}
}

double program1::calcMin()
{
	double min=pList[counter-1].getHeight();
	double temp = 0;
	for (int i = counter; i >= 0; i--)
	{
		temp = pList[i-1].getHeight();
		if (min > temp)
		{
			min = temp;
		}
	}
	minD = min;
	return min;
}

double program1::calcMax()
{
	double max = pList[counter-1].getHeight();
	double temp = 0;
	for (int i = counter; i >= 0; i--)
	{
		temp = pList[i-1].getHeight();
		if (max < temp)
		{
			max = temp;
		}
	}
	maxD = max;
	return max;
}

double program1::calcMin2()//FOR THE 2ND FEATURE
{
    double min=pList[counter].getHand();
    double temp = 0;
    for (int i = counter; i > 0; i--)
    {
        temp = pList[i].getHand();
        if (min > temp)
        {
            min = temp;
        }
    }
    minD = min;
    return min;
}

double program1::calcMax2()//FOR THE 2ND FEATURE
{
    double max = pList[counter].getHand();
    double temp = 0;
    for (int i = counter; i > 0; i--)
    {
        temp = pList[i].getHand();
        if (max < temp)
        {
            max = temp;
        }
    }
    maxD = max;
    return max;
}

double program1::calcMeanM()
{
	double sum = 0;
	double count = 0;
	for (int i = counter; i >= 0; i--)
	{
		if (pList[i-1].getGender() == 'M')
		{
			sum += pList[i-1].getHeight();
			count++;
		}
	}
	double mean = sum / count;
	return mean;
}

double program1::calcMeanF()
{
	double sum = 0;
	double count = 0;
	for (int i = counter; i >= 0; i--)
	{
		if (pList[i-1].getGender() == 'F')
		{
			sum += pList[i-1].getHeight();
			count++;
		}
	}
	double mean = sum / count;
	return mean;
}

double program1::calcStDevM() 
{
	double meanM = this->calcMeanM();
	double sum = 0;
	double result = 0;
	double count = 0;
	for (int i = counter; i >= 0; i--)
	{
		if (pList[i-1].getGender() == 'M')
		{
			result = pow(pList[i-1].getHeight() - meanM, 2);
			sum += result;
			count++;
		}
	}
	return sum / count;
}

double program1::calcStDevF()
{
	double meanF = this->calcMeanF();
	double sum = 0;
	double result = 0;
	double count = 0;
	for (int i = counter; i >= 0; i--)
	{
		if (pList[i-1].getGender() == 'F')
		{
			result = pow(pList[i-1].getHeight() - meanF, 2);
			sum += result;
			count++;
		}
	}
	return sum / count;
}

void program1::calcHistogram() {
	
	for (int k = counter; k >= 0; k--)
	{
		if (pList[k-1].getGender() == 'M')
		{
			int num = this->BF(pList[k-1].getHeight());
			hBM[num] += 1;
		}
		if (pList[k-1].getGender() == 'F')
		{
			int num = this->BF(pList[k-1].getHeight());
			hBF[num] += 1;
		}
	}
	std::cout << "The histogram bins for Male is " << endl;
	for (int i = 0; i < 32; i++)
	{
		std::cout << " " << hBM[i] << " ";
	}
	std::cout << endl << "The histogram bins for Female is " << endl;
	for (int i = 0; i < 32; i++)
	{
		std::cout << " " << hBF[i] << " ";
	}
	std::cout << endl;
}

int program1::BF(double k) {
	double maxM = 83;
	double minM = 52;
	int b = (int) round(31 * ((k - minM) / (maxM - minM)));
	return b;
}

double program1::calcHistProbM(double qInput)
{
    double hProb = 0.0;
    int bIndex = this->BF(qInput);
    hProb = (hBM[bIndex])/(hBM[bIndex]+hBF[bIndex]);
    return hProb;
}

double program1::calcHistProbF(double qInput)
{
    double hProb = 0.0;
    int bIndex = this->BF(qInput);
    hProb = (hBF[bIndex])/(hBM[bIndex]+hBF[bIndex]);
    return hProb;
}

int program1::calcSampleSizeM()
{
    int sizeM = 0;
    for (int i = counter; i >= 0; i--) {
        if (pList[i-1].getGender() == 'M') {
            sizeM++;
        }
    }
    return sizeM;
}

int program1::calcSampleSizeF()
{
    int sizeF = 0;
    for (int i = counter; i >= 0; i--) {
        if (pList[i-1].getGender() == 'F') {
            sizeF++;
        }
    }
    return sizeF;
}

double program1::calcBayProbM(double qInput)
{
    double bayProbF = 0.0;
    double bayProbM = 0.0;
    //bayProb = this->calcSampleSizeM()*((1.0/(sqrt(2.0*PI)*this->calcStDevM()))*exp(-0.5*(pow(((qInput-this->calcMeanM())/this->calcStDevM()),2))));
    
    bayProbF = this->calcSampleSizeF();
    bayProbF = bayProbF * (1.0/(sqrt(2.0*PI)*this->calcStDevF()));
    bayProbF = bayProbF * exp((-0.5)*(pow(((qInput-this->calcMeanF())/this->calcStDevF()),2)));
    bayProbM = this->calcSampleSizeM();
    bayProbM = bayProbM * (1.0/(sqrt(2.0*PI)*this->calcStDevM()));
    bayProbM = bayProbM * exp((-0.5)*(pow(((qInput-this->calcMeanM())/this->calcStDevM()),2)));
    return bayProbM/(bayProbM+bayProbF);
}

double program1::calcBayProbF(double qInput)
{
    double bayProbF = 0.0;
    double bayProbM = 0.0;
    //bayProb = this->calcSampleSizeF()*((1.0/(sqrt(2.0*PI)*this->calcStDevF()))*exp(-0.5*(pow(((qInput-this->calcMeanF())/this->calcStDevF()),2))));
    
    bayProbF = this->calcSampleSizeF();
    bayProbF = bayProbF * (1.0/(sqrt(2.0*PI)*this->calcStDevF()));
    bayProbF = bayProbF * exp((-0.5)*(pow(((qInput-(this->calcMeanF()))/this->calcStDevF()),2)));
    bayProbM = this->calcSampleSizeM();
    bayProbM = bayProbM * (1.0/(sqrt(2.0*PI)*this->calcStDevM()));
    bayProbM = bayProbM * exp((-0.5)*(pow(((qInput-(this->calcMeanM()))/this->calcStDevM()),2)));
    
    return bayProbF/(bayProbM+bayProbF);
}