#include "Repository.h"

Repository::Repository() noexcept = default;

Repository::~Repository() = default;

const std::vector<Activitate>& Repository::getAll() noexcept
{
	return this->activitati;
}

size_t Repository::dimensiune() const noexcept
{
	return this->activitati.size();
}

void Repository::adauga_act_repo(const Activitate& act)
{
	this->activitati.push_back(act);
}

void Repository::sterge_act_repo(const Activitate& act) {
	std::vector<Activitate>::iterator it = remove(this->activitati.begin(), this->activitati.end(), act);
	this->activitati.pop_back();
}

void Repository::modifica_act_repo(const Activitate& act, const Activitate& actN)
{
	std::vector<Activitate>::iterator it = std::find_if(this->activitati.begin(), this->activitati.end(), [act](const Activitate& a) {return a == act; });

	if (it == this->activitati.end())
		throw Inexistenta();
	*it = actN;
}

const Activitate& Repository::cauta_act_repo(const Activitate& act)
{
	std::vector<Activitate>::iterator it = std::find_if(this->activitati.begin(), this->activitati.end(), [act](const Activitate& a) {return a == act; });

	if (it == this->activitati.end())
		throw Inexistenta();

	return *it;

}

FileRepository::FileRepository(std::string fileName) :Repository(), fileName{ fileName }
{
	loadFromFile();
}


void FileRepository::adauga_act_repo(const Activitate& act)
{
	Repository::adauga_act_repo(act);
	writeToFile();
}

void FileRepository::sterge_act_repo(const Activitate& act)
{
	Repository::sterge_act_repo(act);
	writeToFile();
}

void FileRepository::modifica_act_repo(const Activitate& act, const Activitate& actN)
{
	Repository::modifica_act_repo(act, actN);
	writeToFile();
}

void FileRepository::loadFromFile()
{
	std::ifstream fin(fileName);

	if (!fin.is_open()) throw openError();

	while (!fin.eof())
	{
		std::string titlu;
		fin >> titlu;
		if (fin.eof()) break;
		std::string desc;
		fin >> desc;
		std::string tip;
		fin >> tip;
		int durata;
		fin >> durata;

		Activitate act{ titlu, desc,tip, durata };
		Repository::adauga_act_repo(act);
	}
	fin.close();
}

void FileRepository::writeToFile()
{
	std::ofstream fout(fileName);

	if (!fout.is_open()) throw openError();

	for (auto& act : getAll())
	{
		fout << act.get_titlu_act() << '\n';
		fout << act.get_descriere_act() << '\n';
		fout << act.get_tip_act() << '\n';
		fout << act.get_durata_act() << '\n';
		fout << '\n';
	}
	fout.close();
}