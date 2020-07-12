#pragma once
#include <iostream>

using namespace std;

class triple {
private:
	long long  dividend;
	unsigned int divider;

	void Reduction();
	long long NOD(long long a, long long b);
public:
	
	triple(long long input_dividend, int input_divider);
	triple(double input);
	triple();
	triple(const triple& Den);

	//Перегрузка арифметических операций
	triple operator+();
	triple operator-();
	triple operator++();
	triple operator++(int);
	triple operator--();
	triple operator--(int);
	triple operator+(const triple& other);
	triple operator-(const triple& other);
	triple operator*(const triple& other);
	triple operator/(const triple& other);

	//Перегрузка операций сравнения

	bool operator>(const triple& other);
	bool operator<(const triple& other);
	bool operator>=(const triple& other);
	bool operator<=(const triple& other);
	bool operator==(const triple& other);
	bool operator!=(const triple& other);

	//Перегрузка операторов присваивания

	triple operator=(const triple& other);
	triple operator+=(const triple& other);
	triple operator-=(const triple& other);
	triple operator*=(const triple& other);
	triple operator/=(const triple& other);

	//Преобразование типов

	operator float();
	operator double();

	friend ostream& operator<<(ostream& os, const triple& tr);
	friend istream& operator>>(istream& os, triple& tr);
};



