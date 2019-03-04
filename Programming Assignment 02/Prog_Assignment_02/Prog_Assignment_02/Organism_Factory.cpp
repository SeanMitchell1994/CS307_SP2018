/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Organism.cpp
*   Author: Sean Mitchell
*   Desc: Header file for the organism factory class
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "Organism_Factory.h"

using namespace std;

//-----------------------------------
// Constructor
//-----------------------------------
Organism_Factory::Organism_Factory()
{
	// Initialize everything

	parser_org_factory = GeneticsSimDataParser::getInstance();			// Singleton
	chromosome_factory = Chromosome_Factory::getInstance();
}

//-----------------------------------
// Destructor
//-----------------------------------
Organism_Factory::~Organism_Factory()
{

}

//-----------------------------------
// Get the singleton instance
//-----------------------------------
Organism_Factory* Organism_Factory::getInstance()
{
	static Organism_Factory *theInstance = NULL;
	if(theInstance == NULL)
	{
		theInstance = new Organism_Factory();
	}
	return theInstance;
}

Organism* Organism_Factory::Get_Organism(string organism_type)
{
    if(organism_type == "P1")
		return Get_Parent1();
    if(organism_type == "P2")
		return Get_Parent2();
}

Organism* Organism_Factory::Get_Organism(vector<Organism*> parent_vector)
{
	return Get_Child(parent_vector);
}

Organism* Organism_Factory::Get_Parent1()
{
	// Parent1 factory method
	return new Organism(parser_org_factory->getCommonName(), parser_org_factory->getScientificName(), chromosome_factory->Get_ChromosomeP1());
}


Organism* Organism_Factory::Get_Parent2()
{
	// Parent2 factory method
	return new Organism(parser_org_factory->getCommonName(), parser_org_factory->getScientificName(), chromosome_factory->Get_ChromosomeP2());
}


Organism* Organism_Factory::Get_Child(vector<Organism*> parent_vector)
{
	// Child factory method
	return new Organism(parser_org_factory->getCommonName(), parser_org_factory->getScientificName(), chromosome_factory->Get_ChromosomeC(parent_vector));
}