// GenericDocument.cpp : À COMPLÉTER
#include "GenericDocument.h"

GenericDocument::GenericDocument(std::string name, std::string dateTime, std::string description) 
	: AbsDocument(name, dateTime), m_description(description) {}

GenericDocument* GenericDocument::clone(void) const {
	return new GenericDocument(*this);
}


AbsDirectoryComponent& GenericDocument::accept(AddAnnotationVisitor& v) const {
	// TODO: completer
	return v.processGenericDocument(*this);
}
