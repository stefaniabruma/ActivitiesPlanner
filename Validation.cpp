#include "Validation.h"

ValidatorActivitate::ValidatorActivitate() = default;

void ValidatorActivitate::valideaza(const Activitate& act) const
{
	if (act.get_durata_act() <= 0)
		throw Invalid();
}