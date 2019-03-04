/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Organism.h
*   Author: Sean Mitchell
*   Desc: Source file for the master gene class
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include "Master_Gene.h"

Master_Gene::Master_Gene()
{
	// Default constructor
}

Master_Gene::Master_Gene(char* trait_input, char* domDesc_input, char* domSymbol_input, char* recDesc_input, char* recSymbol_input, double *coChance_input)
{
	// Actual constructor
	trait = trait_input;
 	domDesc = domDesc_input;
	domSymbol = domSymbol_input[0];
	recDesc = recDesc_input;
	recSymbol = recSymbol_input[0];
	coChance = *coChance_input;
}

Master_Gene::~Master_Gene()
{
	// Destructor
}

string Master_Gene::Get_Trait()
{
	return trait;
}

string Master_Gene::Get_domDesc()
{
	return domDesc;
}

string Master_Gene::Get_domSymbol()
{
	return domSymbol;
}

string Master_Gene::Get_recDesc()
{
	return recDesc;
}

string Master_Gene::Get_recSymbol()
{	
	return recSymbol;
}

double Master_Gene::Get_coChance()
{
	return coChance;
}
