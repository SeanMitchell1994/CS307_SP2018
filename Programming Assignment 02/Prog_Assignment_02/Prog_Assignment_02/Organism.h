/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Organism.h
*   Author: Sean Mitchell
*   Desc: Header file for the organism class
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/
#ifndef ORGANISM_H
#define ORGANISM_H

#include <string>
#include <vector>

#include "GeneticsSimDataParser.h"
#include "Chromosome.h"

using namespace std;

class Organism
{
	private:
		string commmon_name;
		string scientific_name;
		string genotype;
		char trait[128];
		char domDesc[128];
		char domSymbol[128];
		char recDesc[128];
		char recSymbol[128];

		Chromosome* chromosome;

	public:
		// =======================================
		// Constructors/Destructors
		// =======================================
		//Organism(string, string, char*, GeneticsSimDataParser*);				// Old parent organism constructor
		//Organism(string, string, string, GeneticsSimDataParser*);				// Old child organism constructor
		Organism(char*, char*, Chromosome*);									// New common constructor
		~Organism();

		// =======================================
		// Mutator functions
		// =======================================
		void Set_Common_Name(string);
		void Set_Scientific_Name(string);
		void Set_Genotype(char*);

		// =======================================
		// Accessor functions
		// =======================================
		string Get_Genotype();
		string Get_Common_Name();
		string Get_Scientific_Name();
		vector<vector<Gene*>> Get_Chromosome();
};
#endif
