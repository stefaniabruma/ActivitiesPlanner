#pragma once
#include "Domain.h"
#include <vector>
#include "Exceptions.h"
#include <fstream>


class Repository
{
private:
	std::vector<Activitate> activitati;

public:

	/*
	constructor default - fara parametrii

	la iesire:
	lista este goala
	*/
	Repository() noexcept;

	/*
	destructor

	la iesire:
	repository-ul este distrus
	*/
	virtual ~Repository();

	/*
	constructor de copiere

	parametrii:
	- repo (Repository)

	nu punem la dispozitie constructor de copiere deoarece repo-urile nu pot fi copiate
	*/
	Repository(const Repository& repo) = delete;


	/*
	getAll
	returneaza:
	lista de activitati
	*/
	const std::vector<Activitate>& getAll() noexcept;

	/*
	dimensiune
	returneaza:
	numarul de activitati retinute la momentul actual
	*/

	size_t dimensiune() const noexcept;

	/*
	adauga activitate

	parametrii:
	- act (Activitate)

	la iesire:
	activitatea este adaugata in lista de activitati
	*/
	virtual void adauga_act_repo(const Activitate& act);

	/*
	sterge activitate

	parametrii:
	- act (Activitate)

	la iesire:
	activitatea este stearsa din lista
	*/
	virtual void sterge_act_repo(const Activitate& act);

	/*
	modifica activitate

	parametrii:
	act - activitatea ce trebuie modificata
	actN - activitatea la care va fi setata vechea activitate

	la iesire:
	activitatea act va fi setata la activitatea actN
	*/
	virtual void modifica_act_repo(const Activitate& act, const Activitate& actN);

	/*
	cauta activitate

	parametrii:
	act - activitatea cautata (Activitate)

	returneaza:
	activitatea cautata sau arunca exceptie daca nu exista
	*/
	const Activitate& cauta_act_repo(const Activitate& act);
};

class FileRepository :public Repository
{
private:
	std::string fileName;
	void loadFromFile();
	void writeToFile();
public:


	/*
	constructor cu parametrii
	*/
	FileRepository(std::string FileName);

	/*
	adauga activitate

	parametrii:
	- act (Activitate)

	la iesire:
	activitatea este adaugata in lista de activitati
	*/
	void adauga_act_repo(const Activitate& act) override;

	/*
	sterge activitate

	parametrii:
	- act (Activitate)

	la iesire:
	activitatea este stearsa din lista
	*/
	void sterge_act_repo(const Activitate& act) override;

	/*
	modifica activitate

	parametrii:
	act - activitatea ce trebuie modificata
	actN - activitatea la care va fi setata vechea activitate

	la iesire:
	activitatea act va fi setata la activitatea actN
	*/
	void modifica_act_repo(const Activitate& act, const Activitate& actN) override;
};