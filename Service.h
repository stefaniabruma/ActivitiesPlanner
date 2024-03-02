#pragma once
#include <stdexcept>
#include "Repository.h"
#include "Validation.h"
#include <functional>
#include <algorithm>
#include <random>
#include <map>
#include "Undo.h"
#include "Observer.h"

class Service : public Observable
{
private:
	Repository& repo;
	std::vector<Activitate> curente;
	std::vector<std::unique_ptr<ActiuneUndo>> undoActions;

public:


	Service(Repository& repo) : repo{ repo } {};

	/*
	destructor default
	*/
	~Service();

	/*
	adauga o noua activitate cu datele titlu, desc, tip, durata

	parametrii:
	- titlu (string)
	- desc (string)
	- tip (string)
	- durata (int)

	la iesire:
	service-ul va contine si activitatea cu datele date ca paramterii
	arunca exceptie daca activitatea exista deja
	*/
	void adauga_act_service(const std::string& titlu, const std::string& desc, const std::string& tip, int durata);

	/*
	sterge activitatea cu datele titlu, durata

	parametrii:
	- titlu (string)
	- durata (int)

	la iesire:
	service-ul nu mai contine activitatea cu datele date ca parametrii
	arunca exceptie daca activitatea nu exista
	*/
	void sterge_act_service(const std::string& titlu, int durata);

	/*
	afiseaza toate activitatile

	returneaza:
	lista activitatilor inregistrate la momentul actual
	*/
	const std::vector<Activitate>& getAll_service() const noexcept;

	/*
	modifica activitatea cu datele titlu, durata la activitatea cu datele tiltuN, descN, tipN, durataN

	parametrii:
	- titlu (string)
	- durata (int)
	- titluN (string)
	- descN (string)
	- tipN (string)
	- durataN (int)

	la iesire:
	activitatea cu datele titlu, durata este modificata la activitatea cu datele tiltuN, descN, tipN, durataN
	*/
	void modifica_act_service(const std::string& titlu, int durata, const std::string& titluN, const std::string& descN, const std::string& tipN, int durataN);

	/*
	cauta activitate

	parametrii:
	- titlu (string)
	- durata (int)

	returneaza:
	activitatea identificata de parametrii (Activitate) daca aceasta exista si arunca exceptie in caz contrar
	*/
	const Activitate& cauta_act_service(const std::string titlu, int durata);

	/*
	filtreaza dupa o anumita functie

	parametrii:
	filtrate - lista in care se vor stoca activitatile care corespund filtrului
	functie -  functia dupa care se vor filtra activitatile
	*/
	void filtreaza_service(std::vector<Activitate>& filtrate, std::function<bool(const Activitate&)> functie) const;

	/*
	sorteaza

	paramterii:
	sortate - lista in care se vor stoca activitatile sortate
	functie - functia dupa care se va realiza sortarea
	*/
	void sorteaza_service(std::vector<Activitate>& sortate, std::function<bool(const Activitate&, const Activitate&)> functie) const;

	/*
	goleste lista de activitati curente
	*/
	void goleste_curente_service() noexcept;

	/*
	adauga o activitate in lista de curente

	parametrii:
	act - activitatea de adaugat(Activitate)
	*/
	void adauga_curente_service(const std::string titlu);

	/*
	lungimea listei de activitati curente

	returneaza:
	lungimea listei de activitati curente*/
	size_t lungime_curente_service() const noexcept;

	/*
	genereaza aleatoriu activitati in curente
	*/
	void random_generator_curente(const int& numar);

	/*
	returneaza lista de activitati curente*/
	const std::vector<Activitate>& getAll_curente() const noexcept;

	/*
	returneaza un dicitonar in care cheile sunt tipurile activitatilor iar valorile sunt vectori ce contin activitatile de acel tip*/
	void filtreaza_count_serv(std::map<std::string, std::vector<Activitate>>& dictionar) const;


	/*
	undo la ultima operatie efectuata*/
	void undo();

	/*
	pune in tipuri lista de tipuri disponibile in aplicatie*/
	void tipuri_serv(std::vector<std::string>& tipuri);
};

