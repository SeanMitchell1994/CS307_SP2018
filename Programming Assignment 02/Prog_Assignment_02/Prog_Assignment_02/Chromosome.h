/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Organism.h
*   Author: Sean Mitchell
*   Desc: Header file for the chromosome class
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/
#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <string>
#include <vector>
#include <iostream>

#include "Gene.h"

using namespace std;

class Gene; // Forward definition

class Chromosome
{
	private:
		vector<vector<Gene*>> chromosome_vector;

	public:
		// =======================================
		// Constructors/Destructors
		// =======================================
		Chromosome();		
		Chromosome(vector<vector<Gene*>>);
		~Chromosome();

		// =======================================
		// Mutator functions
		// =======================================
		void Set_Chromosome(int);

		// =======================================
		// Accessor functions
		// =======================================
		vector<vector<Gene*>> Get_Chromosome();

};

#endif
