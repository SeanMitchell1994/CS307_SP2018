/*******************************************************************
*   CS 307 Programming Assignment 1
*   File: Gene.cpp
*   Author: Sean Mitchell
*   Desc: Source file for the gene class
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include <string>
#include <iostream>
#include <algorithm>

#include "Gene.h"

using namespace std;

Gene::Gene()
{
	// Default constructor
	cout << "Gene object created!" << endl;
}

Gene::Gene(Master_Gene* m_gene_input, string allele_1_input, string allele_2_input)
{
	//cout << "Gene object created!" << endl;
	master_gene_ptr = m_gene_input;

	allele_1 = allele_1_input;
	allele_2 = allele_2_input;

	string first_half = allele_1;
	string second_half = allele_2;

	// Swaps the allele inputs so that Tt is equal to tT
	if((std::all_of(first_half.begin(), first_half.end(), islower)) && !(std::all_of(second_half.begin(), second_half.end(), islower)))
	{ 
		transform(second_half.begin(), second_half.end(), second_half.begin(),::tolower);
		transform(first_half.begin(), first_half.end(), first_half.begin(),::toupper);
	}

	// Determines if the gene is dominant or recessive
	if(!(std::all_of(first_half.begin(), first_half.end(), islower)) && !(std::all_of(second_half.begin(), second_half.end(), islower)))
	{
		//phenotype = domDesc;
		phenotype_trait = "homozygous dominant";
		//cout << "homozygous dominant found!" << endl;
	}
	else if (!(std::all_of(first_half.begin(), first_half.end(), islower)) && (std::all_of(second_half.begin(), second_half.end(), islower)))
	{
		//phenotype = domDesc;
		phenotype_trait = "heterozygous dominant";
		//cout << "heterozygous dominant found!" << endl;
	}
	else if ((std::all_of(first_half.begin(), first_half.end(), islower)) && (std::all_of(second_half.begin(), second_half.end(), islower)))
	{
		//phenotype = recDesc;
		phenotype_trait = "homozygous recessive";
		//cout << "homozygous recessive found!" << endl;

	}
	//srand((unsigned int)(time(NULL)));
	double result = rand() /100;
	if(result < master_gene_ptr->Get_coChance())
		crossover_gene = true;
	else
		crossover_gene = false;
		
}

Gene::~Gene()
{
	// Destructor
	delete master_gene_ptr;
	//cout << "Gene object destroyed!" << endl;
}

void Gene::Set_Allele_1(char char_input)
{
	allele_1 = char_input;
}

void Gene::Set_Allele_2(char char_input)
{
	allele_2 = char_input;
}

string Gene::Get_Allele_1()
{
	return allele_1;
}

string Gene::Get_Allele_2()
{
	return allele_2;
}


string Gene::Get_Gene()
{
	gene = allele_1 + allele_2;
	return gene;
}

string Gene::Get_Trait()
{
	return master_gene_ptr->Get_Trait();
}

string Gene::Get_Phenotype()
{
	return phenotype;
}

string Gene::Get_Phenotype_Trait()
{
	return phenotype_trait;
}

bool Gene::Get_Crossover_Gene()
{
	return crossover_gene;
}