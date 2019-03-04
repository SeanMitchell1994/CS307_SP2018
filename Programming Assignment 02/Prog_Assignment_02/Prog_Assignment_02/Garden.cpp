/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Garden.cpp
*   Author: Sean Mitchell
*   Desc: Source file for the garden class
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include <iostream>
#include <stdlib.h>
#include <vector>

#include "GeneticsSimDataParser.h"
#include "Garden.h"

Garden::Garden(char* data_file_input)
{
	//cout << "Garden object created!" << endl;

	// Singleton
	parser_garden = GeneticsSimDataParser::getInstance();
	org_factory = Organism_Factory::getInstance();
	m_gene_factory = Master_Gene_Factory::getInstance();

	cout << "Loaded data file " << data_file_input << endl;
	parser_garden->initDataFile(data_file_input);

	Garden_Main();
}

Garden::~Garden()
{
	// walks through parent and child vectors and calls delete on the object at each index
	parent_vector.clear();
	child_vector.clear();
	//cout << "Garden object deleted!" << endl;
}

void Garden::Garden_Main()
{
	for (int i = 0; i < parser_garden->getGeneCount(); i++)
	{
		// Creates master genes
		parser_garden->getGeneData(trait, domDesc,domSymbol,recDesc,recSymbol,&coChance);
		m_gene_factory->Create_Master_Gene(trait, domDesc, domSymbol,recDesc,recSymbol, &coChance);
	}
	m_gene_factory->Print();

	Create_Parents();
	cout << "Enter the number of offspring to create (between 1 and 1000): ";
	cin >> number_of_children;

	while (number_of_children > 1000 || number_of_children < 0)
	{
		// input validation
		cout << "Error: Provided input is not between 1 and 1000\nEnter the number of offspring to create (between 1 and 1000): ";
		cin >> number_of_children;
	}

	srand((unsigned int)(time(NULL))); // random seed
	cout << "Performing simulation..." << endl;
	Breed();
}

void Garden::Create_Parents()
{
	parent_vector.push_back(org_factory->Get_Organism("P1"));
	parent_vector.push_back(org_factory->Get_Organism("P2"));

	for (int i = 0; i < parent_vector.size(); i++)
	{
		cout << "Sim parent " << (i + 1) << ":\n\tOrganism genus-species: " 
			<< parent_vector[i]->Get_Scientific_Name() 
			<< "\n\tChromosomes: " ;
		for (int j = 0; j < parent_vector[i]->Get_Chromosome().size(); j++)
		{
			for (int k = 0; k < parent_vector[i]->Get_Chromosome()[j].size(); k++)
			{
				cout << "\n\t\tChromosome " << (j + 1) << ":\n\t\t\tGenes Type = " 
				<< parent_vector[i]->Get_Chromosome()[j][k]->Get_Trait()
				<< "\n\t\t\t\tAllele 1: " 
				<< parent_vector[i]->Get_Chromosome()[j][k]->Get_Allele_1()
				<< "\n\t\t\t\tAllele 2: " 
				<< parent_vector[i]->Get_Chromosome()[j][k]->Get_Allele_2() << endl;
			}
		}
	}
	cout << endl << endl;
}

void Garden::Breed()
{	
	for (int i = 0; i < number_of_children; i++)
		child_vector.push_back(org_factory->Get_Organism(parent_vector));

}

vector<Organism*> Garden::Get_Parent_Vector()
{
	return parent_vector;	
}

vector<Organism*> Garden::Get_Child_Vector()
{
	return child_vector;	
}
