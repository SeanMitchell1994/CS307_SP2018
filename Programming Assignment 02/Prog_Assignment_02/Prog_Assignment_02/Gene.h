/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: Gene.h
*   Author: Sean Mitchell
*   Desc: Header file for the gene class
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/
#ifndef GENE_H
#define GENE_H

#include <string>
#include <vector>
#include <sys/types.h>     // needed for the _ftime() function
#include <sys/timeb.h>     // contains definition of _timeb struct
#include <time.h>          // needed for other time functions and structures

#include "Chromosome.h"
#include "Master_Gene.h"

using namespace std;

class Gene
{
	private:
		Master_Gene* master_gene_ptr;

		string allele_1;
		string allele_2;
		string phenotype;
		string gene_trait;
		string gene;
		string phenotype_trait;
		bool crossover_gene;

	public:
		// =======================================
		// Constructors/Destructors
		// =======================================
		Gene();
		Gene(string, char*, char*, char*, char*, char*);
		Gene(Master_Gene*, string, string);
		~Gene();

		// =======================================
		// Mutator functions
		// =======================================
		void Set_Allele_1(char);
		void Set_Allele_2(char);
		void Set_Trait(char*);

		// =======================================
		// Accessor functions (local)
		// =======================================
		string Get_Allele_1();
		string Get_Allele_2();
		string Get_Gene_Attribute();
		string Get_Gene();
		string Get_Trait();
		string Get_Phenotype();
		string Get_Phenotype_Trait();
		bool Get_Crossover_Gene();

		// =======================================
		// Accessor functions (master gene)
		// =======================================
		string Get_Genotype();;
		string Get_domDesc();
		string Get_domSymbol();
		string Get_recDesc();
		string Get_recSymbol();
		double Get_coChance();
};
#endif
