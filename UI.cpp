#include "UI.h"

void UserInterface::start()
{
	lista->setModel(model);

	QHBoxLayout* mainLy = new QHBoxLayout;
	setLayout(mainLy);


	setStyleSheet("background-color:pink;");

	mainLy->addWidget(lista);

	QVBoxLayout* scndLy = new QVBoxLayout;

	mainLy->addLayout(scndLy);

	QFormLayout* formLy = new QFormLayout;
	formLy->addRow("Titlu:", titluTxt);
	formLy->addRow("Descriere:", descTxt);
	formLy->addRow("Tip:", tipTxt);
	formLy->addRow("Durata:", durataTxt);

	scndLy->addLayout(formLy);

	QHBoxLayout* btnLy = new QHBoxLayout;
	btnLy->addWidget(adaugaBtn);
	btnLy->addWidget(stergeBtn);
	btnLy->addWidget(modifBtn);
	btnLy->addWidget(exitBtn);

	QHBoxLayout* btnLy2 = new QHBoxLayout;
	btnLy2->addWidget(undoBtn);
	btnLy2->addWidget(filterBtn);
	btnLy2->addWidget(sortBtn);
	btnLy2->addWidget(deschideCRUD);
	btnLy2->addWidget(deschideRDO);


	QHBoxLayout* btnLyC = new QHBoxLayout;
	btnLyC->addWidget(golesteBtn);
	btnLyC->addWidget(adaugaCBtn);
	btnLyC->addWidget(genereazaBtn);
	btnLyC->addWidget(salveazaBtn);
	btnLyC->addWidget(countBtn);

	scndLy->addLayout(btnLy);
	scndLy->addLayout(btnLy2);
	scndLy->addLayout(btnLyC);

	mainLy->addLayout(scndLy);

	QVBoxLayout* mainLy_modif = new QVBoxLayout;
	QFormLayout* formLy_modif = new QFormLayout;

	formLy_modif->addRow("Titlu nou:", titluNTxt);
	formLy_modif->addRow("Descriere noua:", descNTxt);
	formLy_modif->addRow("Tip nou:", tipNTxt);
	formLy_modif->addRow("Durata noua:", durataNTxt);

	modif_window.setLayout(mainLy_modif);
	mainLy_modif->addLayout(formLy_modif);
	mainLy_modif->addWidget(cnfrmBtn);

	QVBoxLayout* mainLy_extra = new QVBoxLayout;
	extra_window.setLayout(mainLy_extra);

	mainLy_extra->addWidget(lista_extra);

	QVBoxLayout* mainLy_filter = new QVBoxLayout;
	filter_window.setLayout(mainLy_filter);
	QFormLayout* formLy_filter = new QFormLayout;
	formLy_filter->addRow("Filtru:", filtruTxt);
	mainLy_filter->addLayout(formLy_filter);
	QHBoxLayout* btnLy3 = new QHBoxLayout;
	btnLy3->addWidget(descBtn);
	btnLy3->addWidget(tipBtn);
	mainLy_filter->addLayout(btnLy3);

	QVBoxLayout* mainLy_sort = new QVBoxLayout;
	sort_window.setLayout(mainLy_sort);
	QHBoxLayout* btnLy4 = new QHBoxLayout;
	btnLy4->addWidget(titluBtn);
	btnLy4->addWidget(descBtn2);
	btnLy4->addWidget(jointBtn);
	mainLy_sort->addLayout(btnLy4);


	btnDyn->setLayout(btnDynLy);
	btnDynLy->addWidget(new QLabel{ "Tipuri existente: " });
	mainLy->addWidget(btnDyn);

	QVBoxLayout* curenteAdaugaMainLy = new QVBoxLayout;
	QFormLayout* curenteAdaugaFormLy = new QFormLayout;
	curenteAdaugaMainLy->addLayout(curenteAdaugaFormLy);
	curenteAdaugaFormLy->addRow("Titlu:", titluCurente);
	curenteAdaugaMainLy->addWidget(cnfrmAdaugaCBtn);
	curente_adauga_extra_window.setLayout(curenteAdaugaMainLy);

	QVBoxLayout* curenteGenereazaMainLy = new QVBoxLayout;
	QFormLayout* curenteGenereazaFormLy = new QFormLayout;
	curenteGenereazaMainLy->addLayout(curenteGenereazaFormLy);
	curenteGenereazaFormLy->addRow("Numar:", numar);
	curenteGenereazaMainLy->addWidget(cnfrmGenereazaCBtn);
	curente_genereaza_extra_window.setLayout(curenteGenereazaMainLy);

	QVBoxLayout* curenteSalveazaMainLy = new QVBoxLayout;
	QFormLayout* curenteSalveazaFormLy = new QFormLayout;
	curenteSalveazaMainLy->addLayout(curenteSalveazaFormLy);
	curenteSalveazaFormLy->addRow("Fisier:", fisierTxt);
	curenteSalveazaMainLy->addWidget(cnfrmSalveazaCBtn);
	curente_salveaza_extra_window.setLayout(curenteSalveazaMainLy);

	QVBoxLayout* curenteCountMainLy = new QVBoxLayout;
	curente_count_extra_window.setLayout(curenteCountMainLy);
	curenteCountMainLy->addWidget(tipuri);
}

//void UserInterface::loadData()
//{
//	lista->clear();
//
//	std::vector<Activitate> acts = serv.getAll_service();
//
//	for (const Activitate& a : acts)
//	{
//		QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(a.get_titlu_act()) };
//		item->setData(Qt::UserRole, QString::fromStdString(std::to_string(a.get_durata_act())));
//		lista->addItem(item);
//	}
//
//	/*lista->clear();
//	lista->setColumnCount(1);
//	lista->setRowCount(0);
//
//	std::vector<Activitate> acts = serv.getAll_service();
//
//	for (const Activitate& a : acts)
//	{
//		QTableWidgetItem* item = new QTableWidgetItem{ QString::fromStdString(a.get_titlu_act()) };
//		item->setData(Qt::UserRole, QString::fromStdString(std::to_string(a.get_durata_act())));
//		lista->insertRow(lista->rowCount());
//		lista->setItem(lista->rowCount() - 1, lista->columnCount() - 1, item);
//	}*/
//}

void UserInterface::incarca_extra(const std::vector<Activitate>& activitati)
{
	lista_extra->clear();

	for (const Activitate& a : activitati)
	{
		QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(a.get_titlu_act()) };
		item->setData(Qt::UserRole, QString::fromStdString(std::to_string(a.get_durata_act())));
		lista_extra->addItem(item);
	}
}

void UserInterface::connectMethods()
{
	QObject::connect(adaugaBtn, &QPushButton::clicked, [&]()
		{
			auto titlu = titluTxt->text();
			auto desc = descTxt->text();
			auto tip = tipTxt->text();
			auto durata = durataTxt->text();

			titluTxt->clear();
			descTxt->clear();
			tipTxt->clear();
			durataTxt->clear();


			try
			{
				serv.adauga_act_service(titlu.toStdString(), desc.toStdString(), tip.toStdString(), durata.toInt());
			}
			catch (Existenta e)
			{
				QMessageBox::information(nullptr, "Info", e.what());
			}
			catch (Invalid e)
			{
				QMessageBox::information(nullptr, "Info", e.what());
			}

			loadData();

			adaugaButoane();
		});

	QObject::connect(stergeBtn, &QPushButton::clicked, [&]()
		{
			auto titlu = titluTxt->text();
			auto durata = durataTxt->text();

			titluTxt->clear();
			descTxt->clear();
			tipTxt->clear();
			durataTxt->clear();

			try
			{
				serv.sterge_act_service(titlu.toStdString(), durata.toInt());
			}
			catch (Inexistenta e)
			{
				QMessageBox::information(nullptr, "Info", e.what());
			}
			loadData();

			adaugaButoane();
		});

	QObject::connect(modifBtn, &QPushButton::clicked, [&]()
		{
			titluNTxt->setText(titluTxt->text());
			descNTxt->setText(descTxt->text());
			tipNTxt->setText(tipTxt->text());
			durataNTxt->setText(durataTxt->text());

			modif_window.show();
		});


	QObject::connect(cnfrmBtn, &QPushButton::clicked, [&]()
		{
			auto titlu = titluTxt->text();
			auto durata = durataTxt->text();

			auto titluN = titluNTxt->text();
			auto descN = descNTxt->text();
			auto tipN = tipNTxt->text();
			auto durataN = durataNTxt->text();

			try
			{
				this->serv.modifica_act_service(titlu.toStdString(), durata.toInt(), titluN.toStdString(), descN.toStdString(), tipN.toStdString(), durataN.toInt());
				std::cout << "Succes!\n";
			}
			catch (Inexistenta e)
			{
				QMessageBox::information(nullptr, "Info", e.what());
			}
			catch (Nemodificabila e)
			{
				QMessageBox::information(nullptr, "Info", e.what());
			}
			catch (Invalid e)
			{
				QMessageBox::information(nullptr, "Info", e.what());
			}

			titluTxt->clear();
			durataTxt->clear();

			titluNTxt->clear();
			descNTxt->clear();
			tipNTxt->clear();
			durataNTxt->clear();

			loadData();
			modif_window.close();

			adaugaButoane();
		});


	QObject::connect(exitBtn, &QPushButton::clicked, [&]() { close(); });

	QObject::connect(undoBtn, &QPushButton::clicked, [&]()
		{
			try
			{
				serv.undo();
			}
			catch (NoUndo e)
			{
				QMessageBox::information(nullptr, "Info", e.what());
			}

			loadData();

			adaugaButoane();
		});

	QObject::connect(filterBtn, &QPushButton::clicked, [&]()
		{
			filter_window.show();
		});

	QObject::connect(sortBtn, &QPushButton::clicked, [&]()
		{
			sort_window.show();
		});

	QObject::connect(descBtn, &QPushButton::clicked, [&]()
		{
			std::vector<Activitate> filtrate;

			auto filtru = filtruTxt->text().toStdString();
			filtruTxt->clear();

			serv.filtreaza_service(filtrate, [filtru](const Activitate& a) {return a.get_descriere_act() == filtru; });

			incarca_extra(filtrate);

			extra_window.show();

			filter_window.close();

		});

	QObject::connect(tipBtn, &QPushButton::clicked, [&]()
		{
			std::vector<Activitate> filtrate;

			auto filtru = filtruTxt->text().toStdString();
			filtruTxt->clear();

			serv.filtreaza_service(filtrate, [filtru](const Activitate& a) {return a.get_tip_act() == filtru; });

			incarca_extra(filtrate);

			extra_window.show();

			filter_window.close();

		});

	QObject::connect(titluBtn, &QPushButton::clicked, [&]()
		{
			std::vector<Activitate> sortate;

			this->serv.sorteaza_service(sortate, [](const Activitate& act1, const Activitate& act2) {return act1.get_titlu_act() < act2.get_titlu_act(); });

			incarca_extra(sortate);
			extra_window.show();

			sort_window.close();
		});

	QObject::connect(descBtn2, &QPushButton::clicked, [&]()
		{
			std::vector<Activitate> sortate;

			this->serv.sorteaza_service(sortate, [](const Activitate& act1, const Activitate& act2) {return act1.get_descriere_act() < act2.get_descriere_act(); });

			incarca_extra(sortate);
			extra_window.show();

			sort_window.close();
		});

	QObject::connect(jointBtn, &QPushButton::clicked, [&]()
		{
			std::vector<Activitate> sortate;

			this->serv.sorteaza_service(sortate, [](const Activitate& act1, const Activitate& act2) {return act1.get_durata_act() < act2.get_durata_act(); });
			this->serv.sorteaza_service(sortate, [](const Activitate& act1, const Activitate& act2) {return act1.get_tip_act() < act2.get_tip_act(); });

			incarca_extra(sortate);
			extra_window.show();

			sort_window.close();
		});


	QObject::connect(lista_extra, &QListWidget::itemSelectionChanged, [&]()
		{

			titluTxt->clear();
			descTxt->clear();
			tipTxt->clear();
			durataTxt->clear();

			auto sel = lista_extra->selectedItems();

			if (sel.isEmpty())
			{
				titluTxt->setText("");
				descTxt->setText("");
				tipTxt->setText("");
				durataTxt->setText("");
			}
			else
			{
				auto titlu = sel.at(0)->text().toStdString();
				auto durata = sel.at(0)->data(Qt::UserRole).toInt();

				auto act = serv.cauta_act_service(titlu, durata);

				auto desc = QString::fromStdString(act.get_descriere_act());
				auto tip = QString::fromStdString(act.get_tip_act());

				titluTxt->setText(QString::fromStdString(titlu));
				descTxt->setText(desc);
				tipTxt->setText(tip);
				durataTxt->setText(QString::fromStdString(std::to_string(durata)));
			}
		});



	QObject::connect(lista->selectionModel(), &QItemSelectionModel::selectionChanged, [&]()
		{
			titluTxt->clear();
			descTxt->clear();
			tipTxt->clear();
			durataTxt->clear();

			auto sel = lista->selectionModel()->selectedIndexes();

			if (sel.isEmpty())
			{
				titluTxt->setText("");
				descTxt->setText("");
				tipTxt->setText("");
				durataTxt->setText("");
			}
			else
			{
				auto titlu = sel.at(0).data(Qt::DisplayRole).toString().toStdString();
				auto durata = sel.at(0).data(Qt::UserRole).toInt();

				auto act = serv.cauta_act_service(titlu, durata);

				auto desc = QString::fromStdString(act.get_descriere_act());
				auto tip = QString::fromStdString(act.get_tip_act());

				titluTxt->setText(QString::fromStdString(titlu));
				descTxt->setText(desc);
				tipTxt->setText(tip);
				durataTxt->setText(QString::fromStdString(std::to_string(durata)));
			}
		});

	/*QObject::connect(lista, &QTableWi5dget::itemSelectionChanged, [&]()
		{
			titluTxt->clear();
			descTxt->clear();
			tipTxt->clear();
			durataTxt->clear();

			auto sel = lista->selectedItems();

			if (sel.isEmpty())
			{
				titluTxt->setText("");
				descTxt->setText("");
				tipTxt->setText("");
				durataTxt->setText("");
			}
			else
			{
				auto titlu = sel.at(0)->text().toStdString();
				auto durata = sel.at(0)->data(Qt::UserRole).toInt();

				auto act = serv.cauta_act_service(titlu, durata);

				auto desc = QString::fromStdString(act.get_descriere_act());
				auto tip = QString::fromStdString(act.get_tip_act());

				titluTxt->setText(QString::fromStdString(titlu));
				descTxt->setText(desc);
				tipTxt->setText(tip);
				durataTxt->setText(QString::fromStdString(std::to_string(durata)));
			}
		});*/


	QObject::connect(golesteBtn, &QPushButton::clicked, [&]()
		{
			serv.goleste_curente_service();
		});

	QObject::connect(adaugaCBtn, &QPushButton::clicked, [&]()
		{
			curente_adauga_extra_window.show();
		});

	QObject::connect(cnfrmAdaugaCBtn, &QPushButton::clicked, [&]()
		{
			auto titlu = titluCurente->text().toStdString();
			titluCurente->clear();
			serv.adauga_curente_service(titlu);
			curente_adauga_extra_window.close();
		});

	QObject::connect(genereazaBtn, &QPushButton::clicked, [&]()
		{
			curente_genereaza_extra_window.show();
		});

	QObject::connect(cnfrmGenereazaCBtn, &QPushButton::clicked, [&]()
		{
			auto nr = numar->text().toInt();
			numar->clear();
			serv.random_generator_curente(nr);
			curente_genereaza_extra_window.close();
		});

	QObject::connect(salveazaBtn, &QPushButton::clicked, [&]()
		{
			curente_salveaza_extra_window.show();
		});

	QObject::connect(cnfrmSalveazaCBtn, &QPushButton::clicked, [&]()
		{
			auto file = fisierTxt->text().toStdString();
			fisierTxt->clear();

			std::ofstream fout(file);

			std::vector<Activitate> curente = serv.getAll_curente();

			for (const Activitate& a : curente)
				fout << a.to_string() << '\n';

			curente_salveaza_extra_window.close();
		});

	QObject::connect(countBtn, &QPushButton::clicked, [&]()
		{
			tipuri->clear();
			curente_count_extra_window.show();
			std::map<std::string, std::vector<Activitate>> map;
			serv.filtreaza_count_serv(map);

			for (const auto tip : map)
				tipuri->addItem(new QListWidgetItem{ QString::fromStdString(tip.first) + " : " + QString::fromStdString(std::to_string(tip.second.size())) });
		});

	QObject::connect(deschideCRUD, &QPushButton::clicked, [&]()
		{
			cosCRUDGUI* wind = new cosCRUDGUI{ serv };
			wind->show();
		});

	QObject::connect(deschideRDO, &QPushButton::clicked, [&]()
		{
			cosRDOnlyGUI* wind = new cosRDOnlyGUI{ serv };
			wind->show();
		});
}

void UserInterface::adaugaButoane()
{
	std::vector<std::string> tipuri;

	serv.tipuri_serv(tipuri);

	for (QPushButton* btn : butoane)
	{
		delete btn;
	}

	butoane.clear();

	for (std::string& tip : tipuri)
	{
		QPushButton* btn = new QPushButton{ QString::fromStdString(tip) };
		btnDynLy->addWidget(btn);
		butoane.push_back(btn);
		QObject::connect(btn, &QPushButton::clicked, [&, tip]() {
			std::vector<Activitate> filtrate;
			serv.filtreaza_service(filtrate, [tip](const Activitate& a) {return a.get_tip_act() == tip; });
			int numar = filtrate.size();
			QMessageBox::information(nullptr, "Info", QString::number(numar));
			});
	}

}



void cosCRUDGUI::setUp()
{
	QVBoxLayout* curenteMainLy = new QVBoxLayout;
	setLayout(curenteMainLy);

	curenteMainLy->addWidget(new QLabel{ "Activitati curente:" });
	curenteMainLy->addWidget(curente);

	QHBoxLayout* curenteBtnsLy = new QHBoxLayout;
	curenteMainLy->addLayout(curenteBtnsLy);

	curenteBtnsLy->addWidget(golesteBtn);
	curenteBtnsLy->addWidget(adaugaCBtn);
	curenteBtnsLy->addWidget(genereazaBtn);
	curenteBtnsLy->addWidget(salveazaBtn);
	curenteBtnsLy->addWidget(countBtn);

	QVBoxLayout* curenteAdaugaMainLy = new QVBoxLayout;
	QFormLayout* curenteAdaugaFormLy = new QFormLayout;
	curenteAdaugaMainLy->addLayout(curenteAdaugaFormLy);
	curenteAdaugaFormLy->addRow("Titlu:", titluCurente);
	curenteAdaugaMainLy->addWidget(cnfrmAdaugaCBtn);
	curente_adauga_extra_window.setLayout(curenteAdaugaMainLy);

	QVBoxLayout* curenteGenereazaMainLy = new QVBoxLayout;
	QFormLayout* curenteGenereazaFormLy = new QFormLayout;
	curenteGenereazaMainLy->addLayout(curenteGenereazaFormLy);
	curenteGenereazaFormLy->addRow("Numar:", numar);
	curenteGenereazaMainLy->addWidget(cnfrmGenereazaCBtn);
	curente_genereaza_extra_window.setLayout(curenteGenereazaMainLy);

	QVBoxLayout* curenteSalveazaMainLy = new QVBoxLayout;
	QFormLayout* curenteSalveazaFormLy = new QFormLayout;
	curenteSalveazaMainLy->addLayout(curenteSalveazaFormLy);
	curenteSalveazaFormLy->addRow("Fisier:", fisierTxt);
	curenteSalveazaMainLy->addWidget(cnfrmSalveazaCBtn);
	curente_salveaza_extra_window.setLayout(curenteSalveazaMainLy);

	QVBoxLayout* curenteCountMainLy = new QVBoxLayout;
	curente_count_extra_window.setLayout(curenteCountMainLy);
	curenteCountMainLy->addWidget(tipuri);
}

void cosCRUDGUI::loadCurente()
{
	curente->clear();
	const std::vector<Activitate> acts = serv.getAll_curente();
	for (const Activitate& a : acts)
	{
		QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(a.get_titlu_act()) };
		item->setData(Qt::UserRole, QString::fromStdString(std::to_string(a.get_durata_act())));
		curente->addItem(item);
	}
}

void cosCRUDGUI::connectMethods()
{
	serv.addObserver(this);

	QObject::connect(golesteBtn, &QPushButton::clicked, [&]()
		{
			serv.goleste_curente_service();
			loadCurente();
		});

	QObject::connect(adaugaCBtn, &QPushButton::clicked, [&]()
		{
			curente_adauga_extra_window.show();
		});

	QObject::connect(cnfrmAdaugaCBtn, &QPushButton::clicked, [&]()
		{
			auto titlu = titluCurente->text().toStdString();
			titluCurente->clear();
			serv.adauga_curente_service(titlu);
			loadCurente();
			curente_adauga_extra_window.close();
		});

	QObject::connect(genereazaBtn, &QPushButton::clicked, [&]()
		{
			curente_genereaza_extra_window.show();
		});

	QObject::connect(cnfrmGenereazaCBtn, &QPushButton::clicked, [&]()
		{
			auto nr = numar->text().toInt();
			numar->clear();
			serv.random_generator_curente(nr);
			loadCurente();
			curente_genereaza_extra_window.close();
		});

	QObject::connect(salveazaBtn, &QPushButton::clicked, [&]()
		{
			curente_salveaza_extra_window.show();
		});

	QObject::connect(cnfrmSalveazaCBtn, &QPushButton::clicked, [&]()
		{
			auto file = fisierTxt->text().toStdString();
			fisierTxt->clear();

			std::ofstream fout(file);

			std::vector<Activitate> curente = serv.getAll_curente();

			for (const Activitate& a : curente)
				fout << a.to_string() << '\n';

			curente_salveaza_extra_window.close();
		});

	QObject::connect(countBtn, &QPushButton::clicked, [&]()
		{
			tipuri->clear();
			curente_count_extra_window.show();
			std::map<std::string, std::vector<Activitate>> map;
			serv.filtreaza_count_serv(map);

			for (const auto tip : map)
				tipuri->addItem(new QListWidgetItem{ QString::fromStdString(tip.first) + " : " + QString::fromStdString(std::to_string(tip.second.size())) });
		});
}

void cosCRUDGUI::update()
{
	loadCurente();
}

void cosRDOnlyGUI::paintEvent(QPaintEvent* ev)
{
	QPainter p{ this };

	for (const Activitate& a : serv.getAll_curente())
	{
		int x = rand() % (width() - 20);
		int y = rand() % (height() - 20);
		p.drawRect(x, y, 20, 20);
	}
}

void cosRDOnlyGUI::update()
{
	repaint();
}

MyTableModel::MyTableModel(QObject* parent, Service& serv) :QAbstractTableModel(parent), serv { serv } {}

int MyTableModel::rowCount(const QModelIndex& parent) const
{
	return serv.getAll_service().size();
}

int MyTableModel::columnCount(const QModelIndex& parent) const
{
	return 1;
}

QVariant MyTableModel::data(const QModelIndex& index, int role) const
{
	if (role == Qt::DisplayRole)
	{
		Activitate a = serv.getAll_service().at(index.row());
		return QString::fromStdString(a.get_titlu_act());
	}

	if (role == Qt::UserRole)
	{
		Activitate a = serv.getAll_service().at(index.row());
		return QString::fromStdString(std::to_string(a.get_durata_act()));
	}
	return QVariant();
}
