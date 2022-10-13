#pragma once
#include <iostream>
using namespace std;
template <class K, class V>
class Pair
{
	K first;
	V second;
public:
	Pair(K f, V s);
	void setFirst(K f);
	void setSecond(V s);
	K getFirst();
	V getSecond();
	
	template <class K, class V>
	friend ostream& operator<<(ostream& out,Pair<K, V>& pair);
};
template <class K, class V>
ostream& operator<<(ostream& out, Pair<K, V>& pair)
{
	out << "[" << pair.first << ", " << pair.second << "]" << endl;
	return out;
}

template <class K, class V>
Pair<K, V>::Pair(K f, V s)
{
	this->first = f;
	this->second = s;
}

template <class K, class V>
void Pair<K, V>::setFirst(K f)
{
	this->first = f;
}
template <class K, class V>
void Pair<K, V>::setSecond(V s)
{
	this->second = s;
}
template <class K, class V>
K Pair<K, V>::getFirst()
{
	return this->first;
}
template <class K, class V>
V Pair<K, V>::getSecond()
{
	return this->second;
}
