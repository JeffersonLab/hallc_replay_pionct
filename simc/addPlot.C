#include "stree.h"


void addPlot(TString file_name)
{
//read simc root file 
TString data_dir = "/Users/bedier/Documents/Research/Codes/crate/simc/simc_root_files/";
TString root_file  = data_dir + file_name; 

TFile* f1 = new TFile(root_file.Data(), "READ"); 
// get tree "h10" from root file 

TString tree_name = "h10";
TTree*   simc_tree = dynamic_cast<TTree*>(f1->Get(tree_name));



// create hist to store desired physics quantity
TFile* f2 = new TFile("dump.root", "UPDATE");

TH1F* hMMpi = new TH1F("MMpi", "Missing Mass; mmnuc (GeV); Counts", 100, 0.8, 1.2);



simc_tree->Draw("mmnuc >> MMpi");

f2->Write();

f1->Close(); 



}