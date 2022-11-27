#include <string>

#include "Directory.h"
#include "AbsDocument.h"

int Directory::m_indent = 0;

Directory::Directory(std::string name)
	: AbsDirectoryComponent(name)
{
}

Directory::Directory(const Directory& mdd)
	: AbsDirectoryComponent(mdd.m_name)
{
	// À compléter pour copier tous les éléments contenus dans le répertoire
	/*DirectoryComponentPtr directoryPtr = DirectoryComponentPtr(new )*/
	for (auto it = mdd.m_documents.begin(); it != mdd.m_documents.end(); it++)
		/*m_documents.push_back(*it);*/
		addDirectoryComponent(*(*it).get());
}

Directory* Directory::clone(void) const
{
	// À compléter pour construire un nouvel objet Directory en appelant le constructeur de copie
	return new Directory(*this); // À remplacer
}

AbsDirectoryComponent& Directory::accept(AddAnnotationVisitor& v) const {
	// TODO: completer
	return v.processDirectory(*this);
}


AbsDirectoryComponent& Directory::addDirectoryComponent(const AbsDirectoryComponent& member)
{
	// À compléter pour construire par clonage une copie de l'objet reçu en paramètre
	// et l'insérer dans le conteneur de documents. On retourne une référence à l'objet
	// qui vient d'être inséré dans le conteneur.
	m_documents.push_back(DirectoryComponentPtr(member.clone()));
	return *m_documents.back(); // À remplacer 
	//return *this;
}

DirectoryComponentIterator Directory::begin()
{
	return m_documents.begin();
}

DirectoryComponentIterator_const Directory::cbegin() const
{
	return m_documents.cbegin();
}

DirectoryComponentIterator_const Directory::cend() const
{
	return m_documents.cend();
}

DirectoryComponentIterator Directory::end()
{
	return m_documents.end();
}

void Directory::deleteDirectoryComponent(DirectoryComponentIterator_const child)
{
	// À compléter pour éliminer du répertoire l'élément auquel réfère l'itérateur
	m_documents.erase(child);
}

void Directory::deleteAllComponents(void)
{
	// À compléter pour éliminer tous les éléments du répertoire
	for (auto it = cbegin(); it != cend(); ++it)
		deleteDirectoryComponent(it);
}

const AbsDocument* Directory::findDocument(std::string productName) const
{
	// À compléter pour itérer sur les éléments contenus dans le répertoire à la recherche d'un document
	// portant le nom reçu en argument. Si aucun document n'est trouvé, on retourne nullptr
	const AbsDocument* foundDocument = nullptr;
	// À compléter
	for (auto it = cbegin(); it != cend(); ++it) {
		foundDocument = (*it).findDocument(productName);
		if (foundDocument != nullptr && (*foundDocument).getName() == productName)
			return foundDocument;

		// TODO: effacer ca 
		/*if ((*it).getName() == productName)
			return (AbsDocument*)&(*it);
		else if ((*it).findDocument(productName) != nullptr)
			return 
			foundDocument = (*it).findDocument(productName);*/
	}
		//if ((*it).getName() == productName)
			//foundDocument = (AbsDocument*) &(*it); // QUESTION: Quelque chose mieux que un downcast?
	
	return foundDocument;
}

std::ostream& Directory::printToStream(std::ostream& o) const
{
	// À compléter pour imprimer sur un stream une catégorie et son contenu
	o << "Directory: " << m_name << std::endl;
	m_indent++;
	for (auto it = cbegin(); it != cend(); ++it)
		indent(o) << (*it) << std::endl;
	m_indent--;
	return o << std::endl; // TODO: manque identation
}

std::ostream& Directory::indent(std::ostream& o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
	return o;
}
