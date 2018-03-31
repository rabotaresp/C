#include <iostream>
using namespace std;

int main () {
	// Верх звезды
	for (int i=0; i<5; i++){
		for(int k=15; k>i; k--){
			cout << ' ' ;}
			for (int j=1; j<i; j++){
			cout << '*' ;}
			for (int n=0; n<i; n++){
			cout << '*' ;}
			cout <<endl;
}
// Блок середины звезды
	for (int t=21; t<24 ; t=t+3){
		for(int k=25; k>t; k--){
			cout << ' ' ;}
			for (int j=0; j<t; j++){
			cout <<'*';	}
		cout <<endl;	}
		for (int t=17; t<20 ; t=t+3){
		for(int k=23; k>t; k--){
			cout << ' ' ;}
			for (int j=0; j<t; j++){
			cout <<'*';	}
		cout <<endl;	}
		for (int t=11; t<14 ; t=t+3){
		for(int k=20; k>t; k--){
			cout << ' ' ;}
			for (int j=0; j<t; j++){
			cout <<'*';	}
		cout <<endl;	}
				for (int t=17; t<20 ; t=t+3){
		for(int k=23; k>t; k--){
			cout << ' ' ;}
			for (int j=0; j<t; j++){
			cout <<'*';	}
		cout <<endl;	}
			for (int t=21; t<24 ; t=t+3){
		for(int k=25; k>t; k--){
			cout << ' ' ;}
			for (int j=0; j<t; j++){
			cout <<'*';	}
		cout <<endl;	}
		
// Низ звезды		
	for (int k=4; k>0; k--){
		for(int p=15; p>k; p--){
			cout << ' ' ;}
			for (int j=1; j<k; j++){
			cout << '*' ;}
			for (int l=0; l<k; l++){
			cout << '*' ;}
			
	cout <<endl;
		}
}
