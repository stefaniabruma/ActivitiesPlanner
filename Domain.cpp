#pragma once

#include "Domain.h"

Activitate::Activitate(const std::string& titlu, const std::string& descriere, const std::string& tip, const int durata)
{
	this->titlu = titlu;
	this->descriere = descriere;
	this->tip = tip;
	this->durata = durata;
}

Activitate::Activitate()
{
	this->titlu = "";
	this->descriere = "";
	this->tip = "";
	this->durata = 0;
}

Activitate::~Activitate() = default;

Activitate::Activitate(const Activitate& act)
{
	this->titlu = act.titlu;
	this->descriere = act.descriere;
	this->tip = act.tip;
	this->durata = act.durata;
	//std::cout << "copiere\n";
}

Activitate& Activitate::operator=(const Activitate& act)
{
	this->titlu = act.titlu;
	this->descriere = act.descriere;
	this->tip = act.tip;
	this->durata = act.durata;
	return *this;
}

bool Activitate::operator==(const Activitate& act) const noexcept
{
	return this->titlu == act.titlu && this->durata == act.durata;
}


const std::string& Activitate::get_titlu_act() const noexcept
{
	return this->titlu;
}

const std::string& Activitate::get_descriere_act() const noexcept
{
	return this->descriere;
}

const std::string& Activitate::get_tip_act() const noexcept
{
	return this->tip;
}

int Activitate::get_durata_act() const noexcept
{
	return this->durata;
}

std::string Activitate::to_string() const
{
	return "Activitate {" + this->titlu + ", " + this->descriere + ", " + this->tip + ", " + std::to_string(this->durata) + "}";
}
