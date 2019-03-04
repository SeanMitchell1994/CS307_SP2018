/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Organism.cpp
*   Author: Sean Mitchell
*   Desc: Source file for the chromosome factory class
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "Chromosome_Factory.h"

using namespace std;

//-----------------------------------
// Constructor
//-----------------------------------
Chromosome_Factory::Chromosome_Factory()
{
	// Initialize everything

	parser_chromo_factory = GeneticsSimDataParser::getInstance();			// Singleton
	m_gene_factory = Master_Gene_Factory::getInstance();
}

//-----------------------------------
// Destructor
//-----------------------------------
Chromosome_Factory::~Chromosome_Factory()
{

}

//-----------------------------------
// Get the singleton instance
//-----------------------------------
Chromosome_Factory* Chromosome_Factory::getInstance()
{
	static Chromosome_Factory *theInstance = NULL;
	if(theInstance == NULL)
	{
		theInstance = new Chromosome_Factory();
	}
	return theInstance;
}

Chromosome* Chromosome_Factory::Get_ChromosomeP1()
{
	vector<string> strand;
	strand_vector.clear();
	for (int i = 0; i < parser_chromo_factory->getChromosomeCount(); i++)
	{
		parser_chromo_factory->getP1Chromosome(strand1, strand2);

		string temp_1 = string(strand1);
		string temp_2  = string(strand2);

		// 2D vector to store the strands
		strand.push_back(temp_1);
		strand.push_back(temp_2);
		strand_vector.push_back(strand);
		strand.clear();

	}

	return new Chromosome(m_gene_factory->Create_Gene(strand_vector));
}

Chromosome* Chromosome_Factory::Get_ChromosomeP2()
{
	vector<string> strand;
	strand_vector.clear();
	for (int i = 0; i < parser_chromo_factory->getChromosomeCount(); i++)
	{
		parser_chromo_factory->getP2Chromosome(strand1, strand2);

		string temp_1 = string(strand1);
		string temp_2  = string(strand2);

		// 2D vector to store the strands
		strand.push_back(temp_1);
		strand.push_back(temp_2);
		strand_vector.push_back(strand);
		strand.clear();
		
	}
	return new Chromosome(m_gene_factory->Create_Gene(strand_vector));
}


Chromosome* Chromosome_Factory::Get_ChromosomeC(vector<Organism*> parent_vector)
{
	int random_val;
	string genotype_temp1 = "";
	string genotype_temp2 = "";

	vector<string> strand;
	vector<vector<string>> strand1_vector;
	vector<vector<string>> strand2_vector;
	strand.clear();
	strand_vector.clear();

	random_val = Random_Number_Geneator(0,1);
	for (int i = 0; i < parent_vector.size()-1; i++)
	{
		for (int j = 0; j < parent_vector[i]->Get_Chromosome().size(); j++)
		{
			
			for (int k = 0; k < parent_vector[i]->Get_Chromosome()[j].size(); k++)
			{
				random_val = Random_Number_Geneator(0,1);
				if (random_val == 0)
				{
					genotype_temp1 = genotype_temp1 + parent_vector[i]->Get_Chromosome()[j][k]->Get_Allele_1() + " ";
				}
				else if (random_val == 1)
				{
					genotype_temp1 = genotype_temp1 + parent_vector[i]->Get_Chromosome()[j][k]->Get_Allele_2() + " ";
				}
			}

			strand.push_back(genotype_temp1);
			genotype_temp1 = "";		// resets the temp string
		}
		strand_vector.push_back(strand);
		strand.clear();
	}

	for (int i = 0; i < parent_vector.size()-1; i++)
	{
		for (int j = 0; j < parent_vector[i]->Get_Chromosome().size(); j++)
		{
			
			for (int k = 0; k < parent_vector[i]->Get_Chromosome()[j].size(); k++)
			{
				random_val = Random_Number_Geneator(0,1);
				if (random_val == 0)
				{
					genotype_temp1 = genotype_temp1 + parent_vector[i]->Get_Chromosome()[j][k]->Get_Allele_1() + " ";
				}
				else if (random_val == 1)
				{
					genotype_temp1 = genotype_temp1 + parent_vector[i]->Get_Chromosome()[j][k]->Get_Allele_2() + " ";
				}
			}

			strand.push_back(genotype_temp1);
			genotype_temp1 = "";		// resets the temp string
		}
		strand_vector.push_back(strand);
		strand.clear();
	}

	for (int i = 0; i < strand1_vector.size(); i++)
	{
		for (int j = 0; j < strand1_vector[i].size(); j++)
		{	
			strand.clear();

			string tmp1 = strand1_vector[i][j];
			strand.push_back(tmp1);
			strand_vector.push_back(strand);
			strand.clear();

			string tmp2 = strand2_vector[i][j];
			strand.push_back(tmp1);
			strand_vector.push_back(strand);
		}
	}

	return new Chromosome(m_gene_factory->Create_GeneC(strand_vector));
}

int Chromosome_Factory::Random_Number_Geneator(int m_dMinValue, int m_dMaxValue)
{
	int value = m_dMinValue + (rand() % (int)(m_dMaxValue - m_dMinValue + 1));
	return value;
}
