#include <iostream>
#include <cmath>
using namespace std;

 struct Ans {
	 double a, b, c, x1, x2;
	 public:
	 double D() {return b*b - (4*a)*c;}
	 void Discr (double num){
	 if (num < 0) cout << "Not correct numb";
		if (num == 0){
			x1=((-b) + sqrt(D()))/ (2*a);
			cout << "The value of the discriminant X = " << x1 << endl;
						}
				if (num > 0){
					x1=((-b) + sqrt(D()))/ (2*a);
					x2=((-b) - sqrt(D()))/ (2*a);
					cout << "The value of the discriminant X = " << x1 << endl;
					cout << "The value of the discriminant X2 = " << x2 << endl;
								}
}
 };

 
int main()
{
	// a*(x*x)+b*x+c=0
	Ans obj;
	cout << "Enter numb a - ";
	cin >> obj.a;
	cout << "Enter numb b - ";
	cin >> obj.b;
	cout << "Enter numb c - ";
	cin >> obj.c;
	obj.Discr(obj.D());
}
