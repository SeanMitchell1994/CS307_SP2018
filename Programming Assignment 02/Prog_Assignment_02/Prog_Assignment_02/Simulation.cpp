/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Simulation.cpp
*   Author: Sean Mitchell
*   Desc: Source file for the simulation class
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include <iostream>
//#include <iterator>

#include "Simulation.h"
//#include "GeneticsSimDataParser.h"

using namespace std;

Simulation::Simulation()
{
	//cout << "Simulation object created!" << endl;
	Sim_Main();
}

Simulation::~Simulation()
{
	delete sim_garden;
	//cout << "Simulation object deleted!" << endl;
}

void Simulation::Sim_Main()
{
	// Outputs name, course info, etc
	cout << "Sean Mitchell\nCS 307 - 01\nProgramming Assignment 02\n\n";

	cout << "Enter the name of the data file: ";
	cin >> data_file;
	
	sim_garden = new Garden(data_file);
	Sim_Report();
}

void Simulation::Sim_Report()
{
	// ===============================
	// NEW SIM REPORT CODE
	// ===============================

	vector<Organism*>local_child_vector = sim_garden->Get_Child_Vector();
	vector<Organism*>local_parent_vector = sim_garden->Get_Parent_Vector();
	cout << "======================= Results of this Run ======================" << endl;
	crossover_genes = 0;
	for (int j = 0; j < local_child_vector[0]->Get_Chromosome().size(); j++)
	{
		for (int k = 0; k < local_child_vector[0]->Get_Chromosome()[j].size(); k++)
		{
			homo_dom = 0;
			hetero_dom = 0;
			homo_rec = 0;
			for (int i = 0; i < local_child_vector.size(); i++)
			{
				if (local_child_vector[i]->Get_Chromosome()[j][k]->Get_Phenotype_Trait() == "homozygous dominant")
				{
					homo_dom++;

					homo_dom_trait = local_child_vector[i]->Get_Chromosome()[j][k]->Get_Trait();

					phenotype_homo_dom = " " + local_child_vector[i]->Get_Chromosome()[j][k]->Get_Phenotype_Trait() 
						+ " (" + local_child_vector[i]->Get_Chromosome()[j][k]->Get_Phenotype() 
						+ local_child_vector[i]->Get_Chromosome()[j][k]->Get_Allele_1() 
						+ local_child_vector[i]->Get_Chromosome()[j][k]->Get_Allele_2() + ")";
			
				}
				else if (local_child_vector[i]->Get_Chromosome()[j][k]->Get_Phenotype_Trait() == "heterozygous dominant")
				{
					hetero_dom++;
					phenotype_hetero_dom = " " + local_child_vector[i]->Get_Chromosome()[j][k]->Get_Phenotype_Trait() 
						+ " (" + local_child_vector[i]->Get_Chromosome()[j][k]->Get_Phenotype() 
						+ local_child_vector[i]->Get_Chromosome()[j][k]->Get_Allele_1() 
						+ local_child_vector[i]->Get_Chromosome()[j][k]->Get_Allele_2() + ")";
				}

				else if (local_child_vector[i]->Get_Chromosome()[j][k]->Get_Phenotype_Trait() == "homozygous recessive")
				{
					homo_rec++;
					phenotype_homo_rec = " " + local_child_vector[i]->Get_Chromosome()[j][k]->Get_Phenotype_Trait() 
						+ " (" + local_child_vector[i]->Get_Chromosome()[j][j]->Get_Phenotype() 
						+ local_child_vector[i]->Get_Chromosome()[j][k]->Get_Allele_1() 
						+ local_child_vector[i]->Get_Chromosome()[j][k]->Get_Allele_2() + ")";
				}
				if ((local_child_vector[i]->Get_Chromosome()[j][k]->Get_Crossover_Gene()))
				{
					crossover_genes++;
				}
			}
		//cout << homo_dom << endl << hetero_dom << endl << homo_rec << endl;
		cout << "Gene: " << homo_dom_trait << "\n\t" << homo_dom << phenotype_homo_dom 
		<< "\n\t" << hetero_dom << phenotype_hetero_dom 
		<< "\n\t" << homo_rec<< phenotype_homo_rec 
		<< endl << endl;
		}
	}
	cout << "A total of " << crossover_genes << " offspring had at least one crossover gene." << endl << endl;
}