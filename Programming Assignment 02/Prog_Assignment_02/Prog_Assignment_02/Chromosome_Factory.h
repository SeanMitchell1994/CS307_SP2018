/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Organism.h
*   Author: Sean Mitchell
*   Desc: Header file for the chromosome factory class
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>     // needed for the _ftime() function
#include <sys/timeb.h>     // contains definition of _timeb struct
#include <time.h>          // needed for other time functions and structures
#include <algorithm>
#include <string>
#include <sstream>

#include "Chromosome.h"
#include "Organism.h"
#include "Master_Gene_Factory.h"
#include "Gene.h"

using namespace std;

class Chromosome_Factory
{
	private:
		char strand1[128];
		char strand2[128];
		char strand3[128];
		char strand4[128];

		Chromosome_Factory();							// Private Constructor
		GeneticsSimDataParser* parser_chromo_factory;
		Master_Gene_Factory* m_gene_factory;
		vector<vector<string>> strand_vector;


	public:
		~Chromosome_Factory();							// Destructor
		static Chromosome_Factory *getInstance();		// Get the singleton instance

		Chromosome* Get_ChromosomeP1();
		Chromosome* Get_ChromosomeP2();
		Chromosome* Get_ChromosomeC(vector<Organism*>);
		int Random_Number_Geneator(int, int);
};