#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Planificarea_acitivitatilorQTmv.h"

class Planificarea_acitivitatilorQTmv : public QMainWindow
{
    Q_OBJECT

public:
    Planificarea_acitivitatilorQTmv(QWidget *parent = nullptr);
    ~Planificarea_acitivitatilorQTmv();

private:
    Ui::Planificarea_acitivitatilorQTmvClass ui;
};
