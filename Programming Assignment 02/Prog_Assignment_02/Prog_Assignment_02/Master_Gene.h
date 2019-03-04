/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Organism.h
*   Author: Sean Mitchell
*   Desc: Header file for the master gene class
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/
#ifndef MASTER_GENE_H
#define MASTER_GENE_H

#include <string>
#include <vector>

using namespace std;

class Master_Gene
{
	private:
		//string commmon_name;
		//string scientific_name;
		string genotype;
		double coChance;
		string trait;
		string domDesc;
		string domSymbol;
		string recDesc;
		string recSymbol;

	public:
		// =======================================
		// Constructors/Destructors
		// =======================================
		Master_Gene();																// Test constructor
		Master_Gene(char*, char*, char*, char*, char*, double*);					// Actual constructor
		~Master_Gene();

		// =======================================
		// Mutator functions
		// =======================================
		//void Set_Common_Name(string);
		//void Set_Scientific_Name(string);
		//void Set_Genotype(char*);

		// =======================================
		// Accessor functions
		// =======================================
		string Get_Genotype();
		string Get_Trait();
		string Get_domDesc();
		string Get_domSymbol();
		string Get_recDesc();
		string Get_recSymbol();
		double Get_coChance();
};
#endif
