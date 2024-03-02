
#include "Testing.h"

Testing::Testing() noexcept = default;

void Testing::teste_domain() const
{
	std::string titlu = "inot", desc = "activitate fizica", tip = "sport";
	constexpr int durata = 2;
	Activitate act{ titlu, desc, tip, durata };

	assert(act.get_titlu_act() == titlu);
	assert(act.get_descriere_act() == desc);
	assert(act.get_tip_act() == tip);
	assert(act.get_durata_act() == durata);

	Activitate act1;

	assert(act1.get_titlu_act() == "");
	assert(act1.get_descriere_act() == "");
	assert(act1.get_tip_act() == "");
	assert(act1.get_durata_act() == 0);

	assert(!(act1 == act));

	assert(act.to_string() == "Activitate {inot, activitate fizica, sport, 2}");

	act1 = act;

	assert(act1.get_titlu_act() == titlu);
	assert(act1.get_descriere_act() == desc);
	assert(act1.get_tip_act() == tip);
	assert(act1.get_durata_act() == durata);

	Activitate act2(act);

	assert(act2.get_titlu_act() == titlu);
	assert(act2.get_descriere_act() == desc);
	assert(act2.get_tip_act() == tip);
	assert(act2.get_durata_act() == durata);

	assert(act1 == act);

}

void Testing::teste_repository() const
{
	Repository repo;
	assert(repo.dimensiune() == 0);

	std::string titlu = "inot", desc = "activitate fizica", tip = "sport";
	int durata = 2;
	Activitate act{ titlu, desc, tip, durata };

	repo.adauga_act_repo(act);
	assert(repo.dimensiune() == 1);

	std::vector<Activitate> lista = repo.getAll();
	assert(lista.size() == 1);

	Activitate act1 = lista.at(0);
	assert(act1 == act);

	repo.sterge_act_repo(act);
	assert(repo.dimensiune() == 0);

	repo.adauga_act_repo(act);
	titlu = "pictat";
	desc = "activitate creativa";
	tip = "relaxare";
	durata = 1;

	Activitate actN{ titlu, desc, tip, durata };

	repo.modifica_act_repo(act, actN);
	try
	{
		repo.modifica_act_repo(act, actN);
	}
	catch (Inexistenta)
	{
		assert(true);
	}

	lista = repo.getAll();
	act1 = lista.at(0);
	assert(act1 == actN);

	std::string deflt = "default";

	Activitate actD{ titlu, deflt, deflt, durata };

	Activitate actC = repo.cauta_act_repo(actD);

	assert(actC == actN);

	try
	{
		repo.cauta_act_repo(act);
	}
	catch (Inexistenta)
	{
		assert(true);
	}
}

void Testing::teste_file_repo() const
{
	std::ofstream ofs("testerepo.txt");
	ofs.open("testerepo.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	FileRepository repo("testerepo.txt");
	assert(repo.dimensiune() == 0);

	std::string titlu = "inot", desc = "activitate fizica", tip = "sport";
	int durata = 2;
	Activitate act{ titlu, desc, tip, durata };

	repo.adauga_act_repo(act);
	assert(repo.dimensiune() == 1);

	std::vector<Activitate> lista = repo.getAll();
	assert(lista.size() == 1);

	Activitate act1 = lista.at(0);
	assert(act1 == act);

	repo.sterge_act_repo(act);
	assert(repo.dimensiune() == 0);

	repo.adauga_act_repo(act);
	titlu = "pictat";
	desc = "activitate creativa";
	tip = "relaxare";
	durata = 1;

	Activitate actN{ titlu, desc, tip, durata };

	repo.modifica_act_repo(act, actN);
	try
	{
		repo.modifica_act_repo(act, actN);
	}
	catch (Inexistenta)
	{
		assert(true);
	}

	lista = repo.getAll();
	act1 = lista.at(0);
	assert(act1 == actN);

	std::string deflt = "default";

	Activitate actD{ titlu, deflt, deflt, durata };

	Activitate actC = repo.cauta_act_repo(actD);

	assert(actC == actN);

	try
	{
		repo.cauta_act_repo(act);
	}
	catch (Inexistenta)
	{
		assert(true);
	}

	FileRepository reponotempty{ "testereponotempty.txt" };

	try
	{
		FileRepository hdif{ "hdif.txt" };
	}
	catch (openError e)
	{
		assert(strcmp(e.what(), "Error open\n") == 0);
	}

}


void Testing::teste_service() const
{
	std::ofstream ofs("testerepo.txt");
	ofs.open("testerepo.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	FileRepository repo{ "testerepo.txt" };

	Service serv{ repo };

	assert(serv.lungime_curente_service() == 0);

	serv.random_generator_curente(200);

	assert(serv.lungime_curente_service() == 0);

	std::string titlu = "inot", desc = "activitate fizica", tip = "sport";
	constexpr int durata = 2;

	serv.adauga_act_service(titlu, desc, tip, durata);

	try
	{
		serv.adauga_act_service(titlu, desc, tip, durata);
	}
	catch (Existenta e)
	{
		assert(strcmp(e.what(), "Existenta!\n") == 0);
	}

	Activitate act{ titlu, desc, tip, durata };

	std::vector<Activitate> lista = serv.getAll_service();
	assert(lista.size() == 1);

	Activitate act1 = lista.at(0);
	assert(act1 == act);

	std::string ttl = "excursie";
	try
	{
		serv.sterge_act_service(ttl, 7);
	}
	catch (Inexistenta)
	{
		assert(true);
	}

	serv.sterge_act_service(titlu, durata);
	lista = serv.getAll_service();
	assert(lista.size() == 0);

	try
	{
		serv.adauga_act_service(titlu, desc, tip, -1);
	}
	catch (Invalid)
	{
		assert(true);
	}

	std::string titluN = "pictura", descN = "activitate artistica", tipN = "relaxare";
	std::string titlu2 = "invatat", desc2 = "activitate intelectuala", tip2 = "facultate";

	serv.adauga_act_service(titlu, desc, tip, durata);
	serv.adauga_act_service(titlu2, desc2, tip2, 2);

	serv.modifica_act_service(titlu, durata, titluN, descN, tipN, 3);

	lista = serv.getAll_service();
	Activitate actN{ titluN, descN, tipN, 3 };

	assert(lista.at(0) == actN);

	try
	{
		serv.modifica_act_service(titluN, 3, titlu, descN, tipN, -3);

	}
	catch (Invalid e)
	{
		assert(strcmp(e.what(), "Invalid!\n") == 0);
	}

	try
	{
		serv.modifica_act_service(titluN, 3, titlu2, descN, tipN, 2);
	}
	catch (Nemodificabila e)
	{
		assert(strcmp(e.what(), "Activitate cu titlul nou si durata noua existenta deja!\n") == 0);
	}

	try
	{
		serv.modifica_act_service(titlu, 3, titlu, descN, tipN, 3);

	}

	catch (Inexistenta e)
	{
		assert(strcmp(e.what(), "Inexistenta!\n") == 0);
	}
	serv.modifica_act_service(titluN, 3, titluN, descN, tipN, 3);

	Activitate actC = serv.cauta_act_service(titluN, 3);

	lista = serv.getAll_service();
	assert(actC == lista.at(0));

	try
	{
		serv.cauta_act_service(titlu, 1);
	}
	catch (Inexistenta)
	{
		assert(true);
	}

	serv.adauga_act_service(titlu2, desc2, tipN, 3);

	std::vector<Activitate> filtrate;

	serv.filtreaza_service(filtrate, [tipN](const Activitate& act) {return act.get_tip_act() == tipN; });

	lista = serv.getAll_service();


	assert(filtrate.at(0) == lista.at(0));
	assert(filtrate.at(1) == lista.at(2));


	filtrate.clear();

	serv.filtreaza_service(filtrate, [](const Activitate& act) {return act.get_tip_act() == "sport"; });



	assert(filtrate.size() == 0);

	std::vector<Activitate> sortate;

	serv.sorteaza_service(sortate, [](const Activitate& act1, const Activitate& act2) {return act1.get_titlu_act() < act2.get_titlu_act(); });

	assert(sortate.at(0) == lista.at(1));
	assert(sortate.at(1) == lista.at(2));
	assert(sortate.at(2) == lista.at(0));

	assert(serv.lungime_curente_service() == 0);

	serv.adauga_curente_service(titlu2);

	assert(serv.lungime_curente_service() == 2);

	serv.adauga_curente_service(titlu2);

	assert(serv.lungime_curente_service() == 4);

	serv.goleste_curente_service();
	assert(serv.lungime_curente_service() == 0);

	serv.random_generator_curente(30);
	assert(serv.lungime_curente_service() == 30);

	lista = serv.getAll_curente();
	assert(lista.size() == 30);

	serv.goleste_curente_service();
	serv.adauga_curente_service("invatat");
	serv.adauga_curente_service("pictura");
	std::map < std::string, std::vector<Activitate>> dic;

	serv.filtreaza_count_serv(dic);

	assert(dic["relaxare"].size() == 2);
	assert(dic["facultate"].size() == 1);

	std::vector<std::string> tipuri;
	serv.tipuri_serv(tipuri);
	serv.tipuri_serv(tipuri);

}

void Testing::teste_undo() const
{

	std::ofstream ofs("testerepo.txt");
	ofs.open("testerepo.txt", std::ofstream::out | std::ofstream::trunc);
	ofs.close();

	FileRepository repo{ "testerepo.txt" };

	Service serv{ repo };
	std::vector<Activitate> lista;

	lista = serv.getAll_service();
	assert(lista.size() == 0);

	serv.adauga_act_service("inot", "activitate fizica", "sport", 2);
	lista = serv.getAll_service();
	assert(lista.size() == 1);

	serv.undo();
	lista = serv.getAll_service();
	assert(lista.size() == 0);

	serv.adauga_act_service("inot", "activitate fizica", "sport", 2);
	serv.sterge_act_service("inot", 2);
	lista = serv.getAll_service();
	assert(lista.size() == 0);

	serv.undo();
	lista = serv.getAll_service();
	assert(lista.size() == 1);

	lista = serv.getAll_service();
	assert(lista.at(0).get_titlu_act() == "inot");
	assert(lista.at(0).get_descriere_act() == "activitate fizica");
	assert(lista.at(0).get_tip_act() == "sport");
	assert(lista.at(0).get_durata_act() == 2);

	serv.modifica_act_service("inot", 2, "inot", "ceva", "altceva", 2);
	lista = serv.getAll_service();
	assert(lista.at(0).get_titlu_act() == "inot");
	assert(lista.at(0).get_descriere_act() == "ceva");
	assert(lista.at(0).get_tip_act() == "altceva");
	assert(lista.at(0).get_durata_act() == 2);

	serv.undo();
	lista = serv.getAll_service();
	assert(lista.at(0).get_titlu_act() == "inot");
	assert(lista.at(0).get_descriere_act() == "activitate fizica");
	assert(lista.at(0).get_tip_act() == "sport");
	assert(lista.at(0).get_durata_act() == 2);

	serv.modifica_act_service("inot", 2, "pictat", "activitate creativa", "relaxare", 1);
	lista = serv.getAll_service();
	assert(lista.at(0).get_titlu_act() == "pictat");
	assert(lista.at(0).get_descriere_act() == "activitate creativa");
	assert(lista.at(0).get_tip_act() == "relaxare");
	assert(lista.at(0).get_durata_act() == 1);

	serv.undo();
	lista = serv.getAll_service();
	assert(lista.at(0).get_titlu_act() == "inot");
	assert(lista.at(0).get_descriere_act() == "activitate fizica");
	assert(lista.at(0).get_tip_act() == "sport");
	assert(lista.at(0).get_durata_act() == 2);

	serv.undo();

	try
	{
		serv.undo();
	}
	catch (NoUndo e)
	{
		assert(strcmp(e.what(), "Nu mai exista operatii!"));
	}

}

void Testing::toate_testele() const
{
	this->teste_domain();
	this->teste_repository();
	this->teste_service();
	this->teste_undo();
	this->teste_file_repo();
}