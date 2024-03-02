#pragma once
#include "Service.h"
#include <assert.h>
#include <stdexcept>
class Testing
{
public:


	/*
	constructor default
	*/
	const Testing() noexcept;

	/*
	ruleaza testele domeniului de activitati
	*/
	void teste_domain() const;

	/*
	ruleaza testele repository-ului de activitati
	*/
	void teste_repository() const;

	/*
	ruleaza testele repository-ului cu fisiere*/
	void teste_file_repo() const;

	/*
	ruleaza testele service-ului de activitati
	*/
	void teste_service() const;

	/*
	ruleaza testele service-ului cu fisiere*/

	/*
	ruleaza testele pentru undo*/
	void teste_undo() const;

	/*
	ruleaza toate testele
	*/
	void toate_testele() const;

};