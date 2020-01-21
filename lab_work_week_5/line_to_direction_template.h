#pragma once
#include "dependies.h"
template<typename T>
class list_two_direcktion
{
	class Element {
		T data;
		Element* privios;
		Element* next;
	public:
		Element(T data);
	};
public:
	Element* elem;
	list_two_direcktion();
	


};
template<typename T>
list_two_direcktion<T>::Element::Element(T data) {
	this->data = data;
}
template<typename T>
list_two_direcktion<T>::list_two_direcktion() {
	this->elem = nullptr;
}

