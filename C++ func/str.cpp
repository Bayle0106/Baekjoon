#include<iostream>
#include<string>
using namespace std;

 int main(){
	string str = "abcdefghi";

	string sub1 = str.substr(2);
	cout<<sub1<<endl;

	string sub2 = str.substr(3, 6);
	cout<<sub2<<endl;

	
 }