#pragma once
#include <string>
#include <iostream>
class Activitate
{
private:
	std::string titlu;
	std::string descriere;
	std::string tip;
	int durata;

public:
	/*
	constrcutor cu parametrii

	parametrii:
	titlu - titlul activitatii (string)
	descriere - descrierea activitatii (string)
	tip - tipul activitatii (string)
	int - durata actiitatii (string)
	*/
	Activitate(const std::string& titlu, const std::string& descriere, const std::string& tip, int durata);

	/*
	constructor default - fara argumente
	la iesire:
	titlul, descrierea si tipul activitatii sunt string-uri vide
	durata este egala cu  0
	*/
	Activitate();

	/*
	destructor - fara argumente

	la iesire:
	activitatea este distrusa
	*/
	~Activitate();

	/*
	construtctor de copiere

	paramterii:
	act (Activitate)
	*/
	Activitate(const Activitate& act);


	/*
	operatorul de copy-assignment

	parametrii:
	act (Activitate)

	returneaza:
	activitatea (Activitate) cu noii paramterii
	*/
	Activitate& operator=(const Activitate& act);

	/*
	operatorul de egalitate

	paramterii:
	act (Activitate)

	returneaza:
	1 - daca activitatea este egala cu act
	0 - daca activitatea nu este egala cu act
	*/

	bool operator==(const Activitate& act) const noexcept;


	/*
	getter pe titlu

	returneaza:
	titlul activitatii
	*/
	const std::string& get_titlu_act() const noexcept;

	/*
	getter pe descriere

	returneaza:
	descrierea activitatii
	*/
	const std::string& get_descriere_act() const noexcept;

	/*
	getter pe tip

	returneaza:
	tipul activitatii
	*/
	const std::string& get_tip_act() const noexcept;

	/*
	getter pe durata

	returneaza:
	durata activitatii
	*/
	int get_durata_act() const noexcept;

	/*
	returneaza:
	varianta string a activitatii
	*/
	std::string to_string() const;
};