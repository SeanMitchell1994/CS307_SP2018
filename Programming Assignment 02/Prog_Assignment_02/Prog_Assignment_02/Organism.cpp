/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Organism.cpp
*   Author: Sean Mitchell
*   Desc: Header file for the organism class
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include <iostream>

#include "Organism.h"

using namespace std;

Organism::Organism(char* common_name_input, char* scientific_name_input, Chromosome* chromosome_input)
{
	// Parent constructor
	//cout << "Parent created!" << endl;
	chromosome = chromosome_input;
	commmon_name = common_name_input;
	scientific_name = scientific_name_input;
}

Organism::~Organism()
{
	// walk through genotype vector and call delete on each genotype
	//delete chromosome;
	//cout << "Organism object deleted!" << endl;
}

string Organism::Get_Common_Name()
{
	return commmon_name;
}


string Organism::Get_Scientific_Name()
{
	return scientific_name;
}

vector<vector<Gene*>> Organism::Get_Chromosome()
{
	return chromosome->Get_Chromosome();
}
