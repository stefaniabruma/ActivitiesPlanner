#include "Service.h"


Service::~Service()
{
	this->repo.~Repository();
}

void Service::adauga_act_service(const std::string& titlu, const std::string& desc, const std::string& tip, int durata)
{
	Activitate act{ titlu, desc, tip, durata };
	const ValidatorActivitate vldt;
	vldt.valideaza(act);

	std::vector<Activitate> lista = this->repo.getAll();

	try
	{
		this->repo.cauta_act_repo(act);
	}
	catch (Inexistenta)
	{
		this->repo.adauga_act_repo(act);
		this->undoActions.push_back(std::unique_ptr<ActiuneUndo>(new UndoAdauga{ this->repo, act }));
		return;
	}
	throw Existenta();
}

void Service::sterge_act_service(const std::string& titlu, int durata)
{
	std::string desc = "default", tip = "default";
	Activitate act{ titlu, desc, tip, durata };
	std::vector<Activitate> lista = this->repo.getAll();

	act = this->repo.cauta_act_repo(act);

	this->repo.sterge_act_repo(act);
	this->undoActions.push_back(std::unique_ptr<ActiuneUndo>(new UndoSterge{ this->repo, act }));
}

const std::vector<Activitate>& Service::getAll_service() const noexcept
{
	return this->repo.getAll();
}

void Service::modifica_act_service(const std::string& titlu, int durata, const std::string& titluN, const std::string& descN, const std::string& tipN, int durataN)
{
	std::string desc = "default", tip = "default";
	Activitate act{ titlu, desc, tip, durata };
	Activitate actN{ titluN, descN, tipN, durataN };

	const ValidatorActivitate vldt;
	vldt.valideaza(actN);

	std::vector<Activitate> lista = this->repo.getAll();


	for (Activitate a : lista)
		if (actN == a && !(a == act))
			throw Nemodificabila();

	act = this->repo.cauta_act_repo(act);
	this->repo.modifica_act_repo(act, actN);
	this->undoActions.push_back(std::unique_ptr<ActiuneUndo>(new UndoModifica{ this->repo, act, actN }));
}


const Activitate& Service::cauta_act_service(const std::string titlu, int durata)
{
	std::string desc = "default", tip = "default";
	Activitate act{ titlu, desc, tip, durata };

	return this->repo.cauta_act_repo(act);
}

void Service::filtreaza_service(std::vector<Activitate>& filtrate, std::function<bool(const Activitate&)> functie) const
{
	std::vector<Activitate> lista = this->repo.getAll();
	copy_if(lista.begin(), lista.end(), std::back_inserter(filtrate), functie);
}

void Service::sorteaza_service(std::vector<Activitate>& sortate, std::function<bool(const Activitate&, const Activitate&)> functie) const
{
	std::vector<Activitate> lista = this->repo.getAll();

	if (sortate.size() == 0)
		copy(lista.begin(), lista.end(), std::back_inserter(sortate));

	sort(sortate.begin(), sortate.end(), functie);
	/*if(sortate.size() == 0)
		copy(lista.begin(), lista.end(), std::back_inserter(sortate));

	int i, j;
	for (i = 0; i < sortate.size() - 1; i++)
		for (j = 0; j < sortate.size() - i - 1; j++)
			if (!functie(sortate[j], sortate[j+1]))
			{
				Activitate aux;
				aux = sortate[j];
				sortate[j] = sortate[j+1];
				sortate[j+1] = aux;
			}*/
}

void Service::goleste_curente_service() noexcept
{
	this->curente.clear();
	notify();
}

void Service::adauga_curente_service(const std::string titlu)
{
	std::vector<Activitate> lista = this->repo.getAll();
	copy_if(lista.begin(), lista.end(), std::back_inserter(this->curente), [titlu](const Activitate& act) {return act.get_titlu_act() == titlu; });
	notify();
}

size_t Service::lungime_curente_service() const noexcept
{
	return this->curente.size();
}

void Service::random_generator_curente(const int& numar)
{
	std::vector<Activitate> lista = this->repo.getAll();

	if (lista.size() == 0)
		return;

	std::mt19937 mt{ std::random_device{}() };
	std::uniform_int_distribution<> dist(0, lista.size() - 1);

	for (int i = 0; i < numar; i++)
	{
		const int rndNr = dist(mt);
		this->curente.push_back(lista.at(rndNr));
	}

	notify();
}

const std::vector<Activitate>& Service::getAll_curente() const noexcept
{
	return this->curente;
}


void Service::filtreaza_count_serv(std::map<std::string, std::vector<Activitate>>& dictionar) const
{
	for (Activitate a : this->curente)
	{
		std::string tip = a.get_tip_act();
		auto it = dictionar.find(tip);
		if (it == dictionar.end())
		{
			std::vector<Activitate> v;
			v.push_back(a);
			dictionar.insert({ tip, v });
		}
		else
			dictionar[tip].push_back(a);
	}
}

void Service::undo()
{
	if (undoActions.empty())
		throw NoUndo();

	undoActions.back()->doUndo();
	undoActions.pop_back();
}

void Service::tipuri_serv(std::vector<std::string>& tipuri) {

	if (!tipuri.empty())
		tipuri.clear();

	std::vector<Activitate> acts = this->getAll_service();

	for (Activitate& a : acts)
	{
		std::string tip = a.get_tip_act();

		auto it = find(tipuri.begin(), tipuri.end(), tip);

		if (it == tipuri.end())
			tipuri.push_back(tip);
	}
}
