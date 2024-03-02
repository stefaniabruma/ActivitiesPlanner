#pragma once
#include "Domain.h"
#include "Exceptions.h"
class ValidatorActivitate
{
public:

	/*
	constructor default
	*/
	ValidatorActivitate();

	/*
	valideaza o activitate

	la iesire:
	arunca exceptie daca activitatea este invalida
	*/
	void valideaza(const Activitate& act) const;
};