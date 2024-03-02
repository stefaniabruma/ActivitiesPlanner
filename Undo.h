#pragma once
#include "Repository.h"
class ActiuneUndo
{
public:

	//face undo pentru o anume activitate
	virtual void doUndo() = 0;

	//destructor
	virtual ~ActiuneUndo() {};
};

class UndoAdauga : public ActiuneUndo
{
	Activitate actAdaugata;
	Repository& repo;

public:

	//constructor cu parametrii

	UndoAdauga(Repository& repo, const Activitate& activitate) :repo{ repo }, actAdaugata{ activitate } {}

	//undo la adaugarea activitatii actAdaugata
	void doUndo() override
	{
		repo.sterge_act_repo(actAdaugata);
	}
};

class UndoSterge : public ActiuneUndo
{
	Activitate actStearsa;
	Repository& repo;

public:

	//constructor cu parametrii
	UndoSterge(Repository& repo, const Activitate& activitate) :repo{ repo }, actStearsa{ activitate } {}

	//undo la stergerea activitatii actStearsa
	void doUndo() override
	{
		repo.adauga_act_repo(actStearsa);
	}
};

class UndoModifica : public ActiuneUndo
{
	Activitate actModificata;
	Activitate modificare;
	Repository& repo;

public:

	//constructor cu parametrii
	UndoModifica(Repository& repo, const Activitate& actModificata, const Activitate& modificare) :repo{ repo }, actModificata{ actModificata }, modificare{ modificare } {}

	// undo la modificarea activitatii actModificata la activitatea modificare
	void doUndo() override
	{
		repo.modifica_act_repo(modificare, actModificata);
	}
};