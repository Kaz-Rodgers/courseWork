// Ex2.cpp : Rational Calculator
#include<iostream>
using namespace std;

// class
class Rational {
public:
	Rational() {
		num = 1;
		denum = 2;
	}
	Rational(int a, int b) {
		num = a;
		denum = b;
	}
	void Reduce() {
		cout << endl;
		this->Print();
		cout << " = ";
		this->PrintFloating();
		cout << endl;

	}
	void Add(Rational secondNum) {
		this->Print(); 
		cout << " + ";
		secondNum.Print();
		cout << " = ";
		Rational sum((this->num*secondNum.denum + this->denum * secondNum.num), this->denum*secondNum.denum);
		sum.Print();
		sum.Reduce();
		cout << endl;
	}
	void Subtract(Rational secondNum) {
		this->Print();
		cout << " - ";
		secondNum.Print();
		cout << " = ";
		Rational diff((this->num*secondNum.denum - this->denum * secondNum.num), this->denum*secondNum.denum);
		diff.Print();
		diff.Reduce();
		cout << endl;
	}
	void Multiply(Rational secondNum) {
		this->Print();
		cout << " * ";
		secondNum.Print();
		cout << " = ";
		Rational prod((this->num*secondNum.num), this->denum*secondNum.denum);
		prod.Print();
		prod.Reduce();
		cout << endl;
	}
	void Divide(Rational secondNum) {
		this->Print();
		cout << " / ";
		secondNum.Print();
		cout << " = ";
		Rational quo((this->num*secondNum.denum), this->denum*secondNum.num);
		quo.Print();
		quo.Reduce();
		cout << endl;
	}
	void Print() {
		cout << num << "/" << denum;
	}
	 void PrintFloating() {
		 float floatingResult = static_cast<float>(num)  / static_cast<float>(denum);
		 cout << floatingResult << endl;
	}

private:
	int num;
	int denum;
}; Rational Num1(1,3), Num2(7,8);

// Main function
int main() {
	Num1.Add(Num2);
	Num1.Subtract(Num2);
	Num1.Multiply(Num2);
	Num1.Divide(Num2);
	return 0;
}
