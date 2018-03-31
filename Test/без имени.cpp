#include <iostream>
using namespace std;

int main () {
	// Верх звезды
	for (int i=0; i<5; i++){
		for(int k=14; k>i; k--){
			cout << ' ' ;}
			for (int j=1; j<i; j++){
			cout << '*' ;}
			for (int n=0; n<i; n++){
			cout << '*' ;}
			cout <<endl;
}
// Блок середины звезды

	for (int t=16; t<18 ; t=t+2){
		for(int k=22; k>t; k--){
			cout << ' ' ;}
			for (int j=0; j<t; j++){
			cout <<'*';	}
		cout <<endl;	}
			for (int t=20; t<23 ; t=t+3){
		for(int k=24; k>t; k--){
			cout << ' ' ;}
			for (int j=0; j<t; j++){
			cout <<'*';	}
		cout <<endl;	}
		for (int t=26; t<29 ; t=t+3){
		for(int k=27; k>t; k--){
			cout << ' ' ;}
			for (int j=0; j<t; j++){
			cout <<'*';	}
		cout <<endl;	}
		for (int t=20; t<23 ; t=t+3){
		for(int k=24; k>t; k--){
			cout << ' ' ;}
			for (int j=0; j<t; j++){
			cout <<'*';	}
		cout <<endl;	}
		for (int t=16; t<19 ; t=t+3){
		for(int k=22; k>t; k--){
			cout << ' ' ;}
			for (int j=0; j<t; j++){
			cout <<'*';	}
		cout <<endl;	}
		
	/*for (int k=8; k>0; k--){
		for(int p=0; p<6; p++){
			cout << ' ' ;}
			for (int j=0; j<k; j++){
			cout << '*' ;}
			for(int i=6; i>k; i--){
			cout << ' ' ;}
			for(int m=6; m>k; m--){
			cout << ' ' ;}
			for (int n=0; n<k; n++){
			cout << '*' ;}
			
	cout <<endl;
		}*/
}
