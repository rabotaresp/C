#include <iostream>
using namespace std;

int main () {
	// Верх звезды
	for (int i=0; i<6; i++){
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
		for (int t=13; t<16 ; t=t+3){
		for(int k=21; k>t; k--){
			cout << ' ' ;}
			for (int j=0; j<t; j++){
			cout <<'*';	}
		cout <<endl;	}
		
	for (int k=5; k>0; k--){
		for(int p=0; p<10; p++){
			cout << ' ' ;}
			for (int j=0; j<k; j++){
			cout << '*' ;}
			for(int i=5; i>k; i--){
			cout << ' ' ;}
			for(int m=5; m>k; m--){
			cout << ' ' ;}
			for (int l=0; l<k; l++){
			cout << '*' ;}
			
	cout <<endl;
		}
}
