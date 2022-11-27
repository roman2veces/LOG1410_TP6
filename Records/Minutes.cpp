#include <string>

#include "Minutes.h"

Minutes::Minutes(std::string name, std::string dateTime)
	: AbsDocument(name, dateTime)
{}

Minutes* Minutes::clone(void) const
{
	// � compl�ter pour construire un nouvel objet Minutes en appelant le constructeur de copie
	return new Minutes(*this); // � remplacer
}


AbsDirectoryComponent& Minutes::accept(AddAnnotationVisitor& v) const {
	// TODO: completer
	return v.processMinutes(*this);
}