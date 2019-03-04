/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Organism.h
*   Author: Sean Mitchell
*   Desc: Source file for the master gene factory class
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include "Master_Gene_Factory.h"

using namespace std;

//-----------------------------------
// Constructor
//-----------------------------------
Master_Gene_Factory::Master_Gene_Factory()
{
	parser_master_gene_factory = GeneticsSimDataParser::getInstance();
}

//-----------------------------------
// Destructor
//-----------------------------------
Master_Gene_Factory::~Master_Gene_Factory()
{

}

//-----------------------------------
// Get the singleton instance
//-----------------------------------
Master_Gene_Factory* Master_Gene_Factory::getInstance()
{
	static Master_Gene_Factory *theInstance = NULL;
	if(theInstance == NULL)
	{
		theInstance = new Master_Gene_Factory();
	}
	return theInstance;
}

void Master_Gene_Factory::Create_Master_Gene(char* trait_input, char* domDesc_input, char* domSymbol_input, char* recDesc_input, char* recSymbol_input, double *coChance_input)
{
	master_gene_vector.push_back(new Master_Gene(trait_input, domDesc_input, domSymbol_input, recDesc_input, recSymbol_input, coChance_input));
}

vector<vector<Gene*>> Master_Gene_Factory::Create_GeneC(vector<vector<string>> strand_vector)
{
	vector<string> strand1_vec;
	vector<string> strand3_vec;
	vector<vector<string>> strand_vec;
	vector<Gene*> inner;
	gene_vector.clear();

	for (int i = 0; i < strand_vector.size(); i++)
	{
		for (int j = 0; j < strand_vector[i].size(); j++)
		{
			istringstream ss_1(strand_vector[i][j]);
			copy(istream_iterator<string>(ss_1),istream_iterator<string>(),back_inserter(strand1_vec));

			strand_vec.push_back(strand1_vec);
			strand1_vec.clear();
		}
	}

	// Finds the correct master gene for each gene
	int sub_index = 0;
	for (int i = 0; i < strand_vec.size()/2; i++)
	{
		for (int j = 0; j < strand_vec[i].size(); j++)
		{
			if (i == 0)
				sub_index = strand_vec.size()/2;
			else
				sub_index = strand_vec.size()/2 + i;
			string temp_xform = strand_vec[i][j];
			transform(temp_xform.begin(), temp_xform.end(), temp_xform.begin(),::tolower);
			for (int k = 0; k < master_gene_vector.size(); k++)
			{
				if (master_gene_vector[k]->Get_recSymbol() == temp_xform)
				{
					inner.push_back(new Gene(master_gene_vector[k], strand_vec[i][j], strand_vec[sub_index][j]));
					//cout << "rec match found!" << "\nrec symbol: " << master_gene_vector[k]->Get_Trait() << "\nstrand vec: " << temp_xform  << endl << endl;
				}
			}
			sub_index++;
		}
		gene_vector.push_back(inner);
		inner.clear();
	}

	return gene_vector;
}

vector<vector<Gene*>> Master_Gene_Factory::Create_Gene(vector<vector<string>> strand_vector)
{
	vector<string> strand1_vec;
	vector<string> strand3_vec;
	vector<Gene*> inner;
	gene_vector.clear();
	
	// Parses the genes on the chromosome
	for (int i = 0; i < strand_vector.size(); i++)
	{
		for (int j = 0; j < strand_vector[i].size()-1; j++)
		{
			istringstream ss_1(strand_vector[i][0]);
			istringstream ss_2(strand_vector[i][1]);

			copy(istream_iterator<string>(ss_1),istream_iterator<string>(),back_inserter(strand1_vec));
			copy(istream_iterator<string>(ss_2),istream_iterator<string>(),back_inserter(strand3_vec));
		}
	}

	// Finds the correct master gene for each gene
	int sub_index = 0;
	for (int i = 0; i < strand_vector.size(); i++)
	{
		for (int j2 = 0; j2 <= (strand_vector[i][1].length()/2); j2++)
		{
			string temp_xform = strand1_vec[sub_index];
			//cout << "temp xform = " << temp_xform << endl;
			transform(temp_xform.begin(), temp_xform.end(), temp_xform.begin(),::tolower);

			for (int k = 0; k < master_gene_vector.size(); k++)
			{
				if (master_gene_vector[k]->Get_recSymbol() == temp_xform)
				{
					inner.push_back(new Gene(master_gene_vector[k], strand1_vec[sub_index], strand3_vec[sub_index]));
					//cout << "rec match found!" << "\nrec symbol: " << master_gene_vector[k]->Get_Trait() << "\nstrand vec: " << temp_xform  << endl;
				}
			}

			//cout << endl;
			sub_index++;
		}

		gene_vector.push_back(inner);
		inner.clear();
	}

	return gene_vector;
}


void Master_Gene_Factory::Print()
{
	for (int i = 0; i < master_gene_vector.size(); i++)
	{
		cout << "Master Genes:\n\tTrait Name: " << master_gene_vector[i]->Get_Trait()
			<< "\n\t\tDominant Name: " <<  master_gene_vector[i]->Get_domDesc() << " (" << master_gene_vector[i]->Get_domSymbol() 
			<< ")\n\t\tRecessive Name: " << master_gene_vector[i]->Get_recDesc() << " (" << master_gene_vector[i]->Get_recSymbol() << ")" 
			<< "\n\t\tCrossover Chance: " << master_gene_vector[i]->Get_coChance() << endl;
	}
}
