///////////////////////////////////////////////////////////
//  FindDocumentVisitor.cpp
//  Date: 2022-11-15
//  Original author: francois
///////////////////////////////////////////////////////////

#include "FindDocumentVisitor.h"
#include "Instance.h"
#include "Artifact.h"

FindDocumentVisitor::FindDocumentVisitor(const char* documentName)
	: m_searchedName(documentName), m_currentIterator(nullptr)
{
}

void FindDocumentVisitor::processArtifact(Artifact& artifact)
{
	// � compl�ter: v�rifier si le nom du document correspond au nom cherch�
	//              si oui, ajouter l'it�rateur sur ce document dans la liste des art�facts trouv�s
	if (artifact.getName() == m_searchedName)
		m_artifactsFound.push_back(*m_currentIterator);
}

void FindDocumentVisitor::processInstance(Instance& instance)
{
	// � compl�ter: it�rer sur tous les �l�ments de l'instance
	//                   - conserver un pointeur sur l'it�rateur de �l�ment
	//                   - appliquer le visiteur sur l'�l�ment
	for (auto it = instance.begin(); it != instance.end(); ++it) {
		m_currentIterator = &it;
		(*it).accept(*this);
	}
}

FoundArtifactIterator FindDocumentVisitor::begin()
{
	return m_artifactsFound.begin();
}

FoundArtifactIterator_const FindDocumentVisitor::cbegin() const
{
	return m_artifactsFound.begin();
}

FoundArtifactIterator_const FindDocumentVisitor::cend() const
{
	return m_artifactsFound.cend();
}

FoundArtifactIterator FindDocumentVisitor::end()
{
	return m_artifactsFound.end();
}

void FindDocumentVisitor::reset()
{
	m_artifactsFound.clear();
}

