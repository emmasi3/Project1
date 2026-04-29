#pragma once
#include<iostream>
using namespace std;
#include <string>


template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	void show();

	T1 name;
	T2 age;
}; 

template<typename T1, typename T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->name = name;
	this->age = age;
}

template<class T1,class T2>
void Person<T1, T2>::show()
{
	cout << this->name << "\t" << this->age << endl;
}