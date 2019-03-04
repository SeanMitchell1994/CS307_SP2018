/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Garden.h
*   Author: Sean Mitchell
*   Desc: Header file for the garden class
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include <vector>
#include <iterator>

#include "GeneticsSimDataParser.h"
#include "Organism_Factory.h"
#include "Master_Gene_Factory.h"

class Garden
{
	private:
		unsigned int random_seed;
		int number_of_children;

		char data_file[128];
		char genotype[128];
		char strand1[128];
		char strand2[128];
		char trait[128];
		char domDesc[128];
		char domSymbol[128];
		char recDesc[128];
		char recSymbol[128];
		double coChance;

		vector<Organism*> parent_vector;				// This vector stores the parents
		vector<Organism*> child_vector;					// This vector stores the children created
		
		GeneticsSimDataParser* parser_garden;
		Organism_Factory* org_factory;
		Master_Gene_Factory* m_gene_factory;
		
	public:
		// =======================================
		// Constructors/Destructors
		// =======================================
		Garden(char*);
		~Garden();
		
		// =======================================
		// Accessor functions
		// =======================================
		vector<Organism*> Get_Parent_Vector();
		vector<Organism*> Get_Child_Vector();

		// =======================================
		// Mutator functions
		// =======================================
	
		// =======================================
		// Other functions
		// =======================================
		void Garden_Main();
		void Create_Parents();
		void Breed();
		int Random_Number_Geneator(int, int);
};
