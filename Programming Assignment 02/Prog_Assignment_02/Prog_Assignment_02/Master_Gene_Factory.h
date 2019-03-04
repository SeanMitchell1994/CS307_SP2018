/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Organism.h
*   Author: Sean Mitchell
*   Desc: Header file for the master gene factory class
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/
#ifndef GENE_FACTORY_H
#define GENE_FACTORY_H

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

#include "Chromosome.h"
#include "Master_Gene.h"
#include "Gene.h"
#include "GeneticsSimDataParser.h"

using namespace std;

class Master_Gene_Factory
{
	private:
		Master_Gene_Factory();							// Private Constructor
		GeneticsSimDataParser* parser_master_gene_factory;

		vector<Master_Gene*> master_gene_vector;
		vector<vector<Gene*>> gene_vector;

	public:
		~Master_Gene_Factory();							// Destructor
		static Master_Gene_Factory *getInstance();		// Get the singleton instance

		Gene* Get_Gene();
		void Create_Master_Gene(char*, char*, char*, char*, char*, double*);
		vector<vector<Gene*>> Create_Gene(vector<vector<string>>);
		vector<vector<Gene*>> Create_GeneC(vector<vector<string>>);
		void Print();
};
#endif
