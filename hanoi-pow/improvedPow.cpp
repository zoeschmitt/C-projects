#include <iostream>
#include <chrono>

using namespace std;

//improved runnning time pow function
double improvedPow(double x, int y)
{
    double temp;
    
    if(y == 0)
        return 1;
    else if(y < 0) {
        y *= -1;
        x = (1/x);
        return x * pow(x, y - 1);
    }
    else if(y % 2 == 0){
        y = (y/2);
        temp = pow(x, y);
        return temp * temp;
    }
    else {
        y = ((y-1)/2);
        temp = pow(x, y);
        return (x * (temp * temp));
    }
}

int main() 
{
	cout << "To calculate x^y..." << endl;
	
	double x;
	int y;
	cout << "Please enter x: ";
	cin >> x;
	cout << "Please enter y: ";
	cin >> y;
	
	if(x == 0) {
		if (y > 0)
			cout << 0 << endl;
		else
			cout << "x^y is not defined" <<endl;
	}
	else {
		cout << improvedPow(x,y) << endl;
	
    }
		
	return 0;
}

