/*******************************************************************
*   CS 307 Programming Assignment 2
*   File: Simulation.h
*   Author: Sean Mitchell
*   Desc: Header file for the simulation class
*   Date: 4/11/2018
*
*   I attest that this program is entirely my own work
*******************************************************************/

#include <vector>

#include "Garden.h"
#include "GeneticsSimDataParser.h"

class Simulation
{
	private:
		char data_file[128];
		char trait[128];
		char domDesc[128];
		char domSymbol[128];
		char recDesc[128];
		char recSymbol[128];
		double coChance;
		Garden *sim_garden;
		GeneticsSimDataParser* parser;

		string homo_dom_trait;
		string hetero_dom_trait;
		string homo_rec_trait;
		string phenotype_homo_dom;
		string phenotype_hetero_dom;
		string phenotype_homo_rec;

		int homo_dom;
		int hetero_dom;
		int homo_rec;
		int crossover_genes;

	public:
		// =======================================
		// Constructors/Destructors
		// =======================================
		Simulation();
		~Simulation();

		// =======================================
		// Accessor functions
		// =======================================

		// =======================================
		// Mutator functions
		// =======================================
	
		// =======================================
		// Other functions
		// =======================================
		void Sim_Main();
		void Sim_Report();
};
