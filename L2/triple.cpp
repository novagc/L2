#include <iostream>

#include "triple.h"

using namespace std;

long long triple::NOD(long long a, long long b) {
	if (a == b)
		return a;
	if (a > b) {
		swap(a, b);
	}
	return NOD(a, b - a);
}

void triple::Reduction() {
	int a = this->dividend;
	if (a < 0)
		a *= -1;
	long long div = NOD(a, this->divider);
	this->dividend /= div;
	this->divider /= div;
}

triple::triple(long long input_dividend, int input_divider) {//Параметры по умолчанию
	if (input_divider == 0) {
		cout << "Error";
	}
	else if (input_divider < 0) {
		input_dividend *= -1;
		input_divider *= -1;
	}
	dividend = input_dividend;
	divider = input_divider;
	this->Reduction();
}

triple::triple(double input) {
	divider = 1;
	while (double(input) > (long long)input) {// Параметры по умолчанию
		input *= 10;
		divider *= 10;
	};

	dividend = (long long)input;
	this->Reduction();
}

triple::triple() {
	dividend = 1;
	divider = 1;
}

triple::triple(const triple& Den) {//Конструктор копирования
	dividend = Den.dividend;
	divider = Den.divider;
}

//Перегрузка арифметических операций
triple triple::operator+() {
	return *this;
}

triple triple::operator-() {
	this->dividend *= -1;
	return *this;
}

triple triple::operator++() {
	this->dividend += this->divider;
	this->Reduction();
	return *this;
}

triple triple::operator++(int) {
	triple oldVal(*this);
	this->dividend += this->divider;
	this->Reduction();
	return oldVal;
}

triple triple::operator--() {
	this->dividend -= this->divider;
	this->Reduction();
	return *this;
}

triple triple::operator--(int) {
	triple oldVal(*this);
	this->dividend -= this->divider;
	this->Reduction();
	return oldVal;
}

triple triple::operator+(const triple& other) {
	triple Res(*this);
	long long temp = other.dividend * this->divider;
	Res.dividend *= other.divider;
	Res.divider *= other.divider;
	Res.dividend += temp;
	Res.Reduction();
	return Res;
}

triple triple::operator-(const triple& other) {
	triple Res(*this);
	long long temp = other.dividend * this->divider;
	Res.dividend *= other.divider;
	Res.divider *= other.divider;
	Res.dividend -= temp;
	Res.Reduction();
	return Res;
}

triple triple::operator*(const triple& other) {
	triple Res(*this);
	Res.dividend *= other.dividend;
	Res.divider *= other.divider;
	Res.Reduction();
	return Res;
}

triple triple::operator/(const triple& other) {
	triple Res(*this);
	Res.dividend *= other.divider;
	Res.divider *= other.dividend;
	Res.Reduction();
	return Res;
}
//Перегрузка операций сравнения
bool triple::operator>(const triple& other) {
	double temp1 = (double)this->dividend / this->divider, temp2 = (double)other.dividend / other.divider;
	if (temp1 > temp2)
		return 1;
	else
		return 0;
}

bool triple::operator<(const triple& other) {
	double temp1 = (double)this->dividend / this->divider, temp2 = (double)other.dividend / other.divider;
	if (temp1 < temp2)
		return 1;
	else
		return 0;
}

bool triple::operator>=(const triple& other) {
	double temp1 = (double)this->dividend / this->divider, temp2 = (double)other.dividend / other.divider;
	if (temp1 >= temp2)
		return 1;
	else
		return 0;
}

bool triple::operator<=(const triple& other) {
	double temp1 = (double)this->dividend / this->divider, temp2 = (double)other.dividend / other.divider;
	if (temp1 <= temp2)
		return 1;
	else
		return 0;
}

bool triple::operator==(const triple& other) {
	double temp1 = (double)this->dividend / this->divider, temp2 = (double)other.dividend / other.divider;
	if (temp1 == temp2)
		return 1;
	else
		return 0;
}

bool triple::operator!=(const triple& other) {
	double temp1 = (double)this->dividend / this->divider, temp2 = (double)other.dividend / other.divider;
	if (temp1 != temp2)
		return 1;
	else
		return 0;
}

//Перегрузка операторов присваивания

triple triple::operator=(const triple& other) {
	this->dividend = other.dividend;
	this->divider = other.divider;
	return *this;
}

triple triple::operator+=(const triple& other) {
	long long temp = other.dividend * this->divider;
	this->dividend *= other.divider;
	this->divider *= other.divider;
	this->dividend += temp;
	this->Reduction();
	return *this;
}
triple triple::operator-=(const triple& other) {
	long long temp = other.dividend * this->divider;
	this->dividend *= other.divider;
	this->divider *= other.divider;
	this->dividend -= temp;
	this->Reduction();
	return *this;
}
triple triple::operator*=(const triple& other) {
	this->dividend *= other.divider;
	this->divider *= other.divider;
	this->Reduction();
	return *this;
}
triple triple::operator/=(const triple& other) {
	this->dividend *= other.divider;
	this->divider *= other.divider;
	this->Reduction();
	return *this;
}

//Преобразование типов

triple::operator float() {
	return float(this->dividend) / this->divider;
}

triple::operator double() {
	return double(this->dividend) / this->divider;
}

ostream& operator<<(ostream& os, const triple& tr) {//Перегрузка ВЫВОДА
	if (tr.divider == 0)
		os << "Error";
	else if (tr.divider != 1)
		os << tr.dividend << '/' << tr.divider;
	else
		os << tr.dividend;
	return os;
}

istream& operator>>(istream& os, triple& tr) {//Перегрузка ВВОДА
	char temp;
	os >> tr.dividend >> temp >> tr.divider;
	return os;
}
