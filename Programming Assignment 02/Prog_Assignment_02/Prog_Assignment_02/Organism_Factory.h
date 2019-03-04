/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Organism.h
*   Author: Sean Mitchell
*   Desc: Header file for the organism factory class
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include <string>

#include "Organism.h"
#include "Chromosome_Factory.h"
#include "Gene.h"

using namespace std;

class Organism_Factory
{
	private:
		char strand1[128];
		char strand2[128];
		char strand3[128];
		char strand4[128];

		Organism_Factory();							// Private Constructor
		GeneticsSimDataParser* parser_org_factory;
		Chromosome_Factory* chromosome_factory;
		Organism* Create_Parent();
		Organism* Create_Child();

		vector<Chromosome*> chromosome_vector;

	public:
		~Organism_Factory();						// Destructor
		static Organism_Factory *getInstance();		// Get the singleton instance

		Organism* Get_Parent1();				
		Organism* Get_Parent2();				
		Organism* Get_Child(vector<Organism*> parent_vector);			
		Organism* Get_Organism(string);
		Organism* Get_Organism(vector<Organism*>);
};
