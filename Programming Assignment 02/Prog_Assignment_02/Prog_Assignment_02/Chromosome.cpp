/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Organism.h
*   Author: Sean Mitchell
*   Desc: source file for the chromosome class
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include "Chromosome.h";

using namespace std;

//-----------------------------------
// Constructor
//-----------------------------------
Chromosome::Chromosome()
{
	//chromosome_vector.push_back("Test");
	cout << "Chromosome object created!" << endl;
}

Chromosome::Chromosome(vector<vector<Gene*>> gene_vector)
{
	// Parent chromosome constructor

	//cout << "Chromosome object created!" << endl;
	chromosome_vector = gene_vector;
	
}

//-----------------------------------
// Destructor
//-----------------------------------
Chromosome::~Chromosome()
{
	// Destructor
	chromosome_vector.clear();
	//cout << "Chromosome object destroyed!" << endl;
}

vector<vector<Gene*>> Chromosome::Get_Chromosome()
{
	return chromosome_vector;
}
/*
vector<Gene*> Chromosome::Get_Chromosome_Vector()
{
	return chromosome_vector;
}
*/