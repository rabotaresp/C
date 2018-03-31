#include <iostream>
using namespace std;
//1
void One (int a = 1){						
					for (int i=0; i<3; i++)
					{
					cout << ' ' << '*' << endl;
					}
					return;
}	
//2
void Two (int a = 1){						
					for (int i=0; i<3; i++)
					{
						for(int i = 0; i<2; i++)
						{
						cout << ' ' << '*' ;
						}
					cout << endl;
					}
					return;
}	
//3
void Three (int a = 1){						
					for (int i=0; i<3; i++)
					{
						for(int i = 0; i<3; i++)
						{
						cout << ' ' << '*' ;
						}
					cout << endl;
					}
					return;
}	
//4
void Four (int a = 1)
					{	
					for (int k=3; k>0; k--){
						for(int p=4; p>k; p--){
			cout << ' ' ;}
			for (int j=1; j<k+k; j++){
			cout << ' ' ;}
			for (int l=0; l<k; l++){
			cout << '*' ;}
			
	cout <<endl;
		}	
			return;
}	
//5
void Five (int a = 1){						
					for (int i = 0; i < 1; i++)
					{
					cout << ' ' << '*' << ' ' << ' ' << ' ' << '*' << endl;
					cout << ' ' << ' ' << '*' << ' ' << '*' << endl;
					cout << ' ' << ' ' << ' ' << '*' << endl;
					}
					return;
}	
//6
void Six (int a = 1){						
					for (int i = 0; i < 1; i++)
					{
					cout << ' ' << '*' << ' ' << ' ' << ' ' << '*' << ' ' << '*' << endl;
					cout << ' ' << ' ' << '*' << ' ' << '*' << ' ' << ' ' << '*' << endl;
					cout << ' ' << ' ' << ' ' << '*' << ' ' << ' ' << ' ' << '*' << endl;
					} 
					return;
}	
//7
void Sev (int a = 1){						
					for (int i = 0; i < 1; i++)
					{
					cout << ' ' << '*' << ' ' << ' ' << ' ' << '*' << ' ' << '*' << ' ' << '*' << endl;
					cout << ' ' << ' ' << '*' << ' ' << '*' << ' ' << ' ' << '*' << ' ' << '*' << endl;
					cout << ' ' << ' ' << ' ' << '*' << ' ' << ' ' << ' ' << '*' << ' ' << '*' << endl;
					} 
					return;
}				
//8
void Oct (int a = 1){						
					for (int i = 0; i < 1; i++)
					{
					cout << ' ' << '*' << ' ' << ' ' << ' ' << '*' << ' ' << '*' << ' ' << '*' << ' ' << '*' << endl;
					cout << ' ' << ' ' << '*' << ' ' << '*' << ' ' << ' ' << '*' << ' ' << '*' << ' ' << '*' << endl;
					cout << ' ' << ' ' << ' ' << '*' << ' ' << ' ' << ' ' << '*' << ' ' << '*' << ' ' << '*' << endl;
					} 
					return;
}				
//9
void Nine (int a = 1){						
					for (int i = 0; i < 1; i++)
					{
					cout << '*' << ' ' << '*' << ' ' << '*' << endl;
					cout << '*' << ' ' << ' ' << '*' << ' ' << endl;
					cout << '*' << ' ' << '*' << ' ' << '*' << endl;
					} 
					return;
}				
//10
void Dec (int a = 1){						
					for (int i = 0; i < 1; i++)
					{
					cout << ' ' << '*' << ' ' << '*' << endl;
					cout << ' ' << ' ' << '*' << ' ' << endl;
					cout << ' ' << '*' << ' ' << '*' << endl;
					} 
					return;
}				

int main () {
	int b;
		cout << "Input num for 1 to 10 - ";
		cin >> b;
	if (b == 1) One();
	if (b == 2) Two();
	if (b == 3) Three();
	if (b == 4) Four();
	if (b == 5) Five();
	if (b == 6) Six();
	if (b == 7) Sev();
	if (b == 8) Oct();
	if (b == 9) Nine();
	if (b == 10) Dec();
							
					

}
