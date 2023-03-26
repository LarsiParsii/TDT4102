#include "std_lib_facilities.h"
#include "animals.h"

int main() {
	testAnimal();
	return 0;
}

/* TEORIOPPGAVER
 *
 * 1a)   Public: Medlemsfunksjonen er synlig for alle, både innenfor og utenfor klassen.
 *       Protected: Funksjonen kan nås innad i selve klassen, samt for dens subklasser.
 *       Private: Funksjonen er kun synlig for selve klassen, og kan ikke nås utenfra.
 *
 * 1d)	Dersom jeg fjerner virtual fra foran toString() i Animal-klassen får jeg en feilmelding
 * 		da jeg har implementert "override" nøkkelordet i subklassene. Fjerner jeg dette får
 * 		jeg ikke fått noen feilmelding og superklassens funksjon blir ikke  erstattet.
 * 		Dette gjør at det vil bli printet "Animal" og ikke "Cat"/"Dog" når toString() kalles.
 */