#pragma once
#include <exception>
#include <string>

class Existenta : public std::exception
{
public:
	/*
	returneaza mesajul exceptiei*/
	const char* what() noexcept;
};

class Inexistenta : public std::exception {
public:
	/*
	returneaza measajul exceptiei*/
	const char* what() noexcept;
};

class Nemodificabila : public std::exception {
public:
	/*
	returneaza measajul exceptiei*/
	const char* what() noexcept;
};

class Invalid : public std::exception {
public:
	/*
	returneaza measajul exceptiei*/
	const char* what() noexcept;
};

class NoUndo : public std::exception {
public:
	/*
	returneaza measajul exceptiei*/
	const char* what() noexcept;
};

class openError : public std::exception {
public:
	/*
	returneaza measajul exceptiei*/
	const char* what() noexcept;
};