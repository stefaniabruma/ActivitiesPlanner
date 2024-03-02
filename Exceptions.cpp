#include "Exceptions.h"

const char* Inexistenta::what() noexcept
{
	return "Inexistenta!\n";
}

const char* Existenta::what() noexcept
{
	return "Existenta!\n";
}

const char* Nemodificabila::what() noexcept
{
	return "Activitate cu titlul nou si durata noua existenta deja!\n";
}

const char* Invalid::what() noexcept
{
	return "Invalid!\n";
}

const char* NoUndo::what() noexcept
{
	return "Nu mai exista operatii!\n";
}

const char* openError::what() noexcept
{
	return "Error open\n";
}
