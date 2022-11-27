	#include <string>

#include "Agenda.h"

Agenda::Agenda(std::string name, std::string dateTime)
	: AbsDocument(name, dateTime)
{
}

AbsDirectoryComponent& Agenda::accept(AddAnnotationVisitor& v) const {
	// TODO: completer
	return v.processAgenda(*this);
}


Agenda* Agenda::clone(void) const
{
	// QUESTION: Pas de constructeur de copie ??
	// À compléter pour construire un nouvel objet Agenda en appelant le constructeur de copie
	return new Agenda(m_name, getDateTime()); // À remplacer
}