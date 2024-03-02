#pragma once
#include "Service.h"
#include <qlabel.h>
#include <qpushbutton.h>
#include <qboxlayout.h>
#include <qlineedit.h>
#include <qformlayout.h>
#include <qlistwidget.h>
#include <qmessagebox.h>
#include <qpalette.h>
#include <qbrush.h>
#include <fstream>
#include <qtablewidget.h>
#include <qpainter.h>

class UserInterface : public QWidget
{
private:

	Service& serv;
	//QListWidget* lista = new QListWidget;
	//QTableWidget* lista = new QTableWidget;
	QListView* lista;
	MyTableModel* model;
	QLineEdit* titluTxt = new QLineEdit;
	QLineEdit* descTxt = new QLineEdit;
	QLineEdit* tipTxt = new QLineEdit;
	QLineEdit* durataTxt = new QLineEdit;
	QPushButton* adaugaBtn = new QPushButton{ "&Adauga" };
	QPushButton* stergeBtn = new QPushButton{ "&Sterge" };

	QPushButton* modifBtn = new QPushButton{ "&Modifica" };
	QWidget modif_window;
	QLineEdit* titluNTxt = new QLineEdit;
	QLineEdit* descNTxt = new QLineEdit;
	QLineEdit* tipNTxt = new QLineEdit;
	QLineEdit* durataNTxt = new QLineEdit;
	QPushButton* cnfrmBtn = new QPushButton{ "&Confirma" };

	QPushButton* exitBtn = new QPushButton{ "&Exit" };
	QPushButton* undoBtn = new QPushButton{ "&Undo" };
	QPushButton* filterBtn = new QPushButton{ "&Filtreaza" };
	QPushButton* sortBtn = new QPushButton{ "&Sorteaza" };


	QWidget filter_window;
	QLineEdit* filtruTxt = new QLineEdit;
	QPushButton* descBtn = new QPushButton{ "&Dupa descriere" };
	QPushButton* tipBtn = new QPushButton{ "&Dupa tip" };

	QWidget sort_window;
	QPushButton* titluBtn = new QPushButton{ "&Dupa titlu" };
	QPushButton* descBtn2 = new QPushButton{ "&Dupa descriere" };
	QPushButton* jointBtn = new QPushButton{ "&Dupa tip + durata" };


	QWidget extra_window;
	QListWidget* lista_extra = new QListWidget;

	QWidget* btnDyn = new QWidget;
	QVBoxLayout* btnDynLy = new QVBoxLayout;

	std::vector<QPushButton*> butoane;

	QPushButton* golesteBtn = new QPushButton{ "&Goleste curente" };
	QPushButton* adaugaCBtn = new QPushButton{ "&Adauga in curente" };
	QPushButton* genereazaBtn = new QPushButton{ "&Genereaza aleator in curente" };
	QPushButton* salveazaBtn = new QPushButton{ "&Salveaza curente in fisier" };
	QPushButton* countBtn = new QPushButton{ "&Count curente dupa tip" };


	QWidget curente_adauga_extra_window;
	QLineEdit* titluCurente = new QLineEdit;
	QPushButton* cnfrmAdaugaCBtn = new QPushButton{ "&Confirma" };

	QWidget curente_genereaza_extra_window;
	QLineEdit* numar = new QLineEdit;
	QPushButton* cnfrmGenereazaCBtn = new QPushButton{ "&Confirma" };

	QWidget curente_salveaza_extra_window;
	QLineEdit* fisierTxt = new QLineEdit;
	QPushButton* cnfrmSalveazaCBtn = new QPushButton{ "&Confirma" };

	QWidget curente_count_extra_window;
	QListWidget* tipuri = new QListWidget;

	QPushButton* deschideCRUD = new QPushButton{ "&Fereastra curente - CRUD" };
	QPushButton* deschideRDO = new QPushButton{ "&Fereastra curente - RDO" };


	void start();
	void loadData();
	void incarca_extra(const std::vector<Activitate>& activitati);
	void connectMethods();
	void adaugaButoane();
	void loadCurente();

public:
	UserInterface(Service& serv) : serv{ serv } { start(); loadData(); connectMethods(); adaugaButoane(); };

};

class cosCRUDGUI : public QWidget, public Observer
{
private:
	Service& serv;
	QListWidget* curente = new QListWidget;
	QPushButton* golesteBtn = new QPushButton{ "&Goleste" };
	QPushButton* adaugaCBtn = new QPushButton{ "&Adauga" };
	QPushButton* genereazaBtn = new QPushButton{ "&Genereaza aleator" };
	QPushButton* salveazaBtn = new QPushButton{ "&Salveaza in fisier" };
	QPushButton* countBtn = new QPushButton{ "&Count dupa tip" };

	QWidget curente_adauga_extra_window;
	QLineEdit* titluCurente = new QLineEdit;
	QPushButton* cnfrmAdaugaCBtn = new QPushButton{ "&Confirma" };

	QWidget curente_genereaza_extra_window;
	QLineEdit* numar = new QLineEdit;
	QPushButton* cnfrmGenereazaCBtn = new QPushButton{ "&Confirma" };

	QWidget curente_salveaza_extra_window;
	QLineEdit* fisierTxt = new QLineEdit;
	QPushButton* cnfrmSalveazaCBtn = new QPushButton{ "&Confirma" };

	QWidget curente_count_extra_window;
	QListWidget* tipuri = new QListWidget;

	void setUp();
	void connectMethods();
	void loadCurente();

	void update() override;

public:
	cosCRUDGUI(Service& serv) :serv{ serv }
	{
		setUp();
		connectMethods();
		loadCurente();
	}

	~cosCRUDGUI()
	{
		serv.removeObserver(this);
	}
};

class cosRDOnlyGUI : public QWidget, public Observer
{
private:

	Service& serv;
	void update() override;

public:

	cosRDOnlyGUI(Service& serv) : serv{ serv }
	{
		serv.addObserver(this);
	}

	void paintEvent(QPaintEvent* ev) override;

	~cosRDOnlyGUI()
	{
		serv.removeObserver(this);
	}
};

class MyTableModel :public QAbstractTableModel
{
private:
	Service& serv;

public:
	MyTableModel(QObject* parent, Service& serv);

	int rowCount(const QModelIndex& parent = QModelIndex()) const override;

	int columnCount(const QModelIndex& parent = QModelIndex()) const override;

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

};