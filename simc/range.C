#include "stree.h"

void range()
{   
    // get file and tree 

    TString fname = "simc_root_files/H_rp2.root"; 
    TString tree_name = "h10"; 
    
    TFile* fsim = new TFile(fname, "read"); 
    TTree* simtree = get_tree(fsim, tree_name); 

   /* simtree->Draw("mmnuc>>htrial"); 
    TH1F *htrial = (TH1F*)gDirectory->Get("htrial");
    int binmin = htrial->FindFirstBinAbove(0.);
    int binmax = htrial->FindLastBinAbove(0.);
    auto xMax = htrial->GetXaxis()->GetBinCenter(binmax);
    auto xMin = htrial->GetXaxis()->GetBinCenter(binmin); 
    std::cout << "rang is " << xMin << " - " << xMax; */




}