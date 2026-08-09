#include "stree.h"
void tstflow(){

    // 1- open simc root file and read tree 
     TFile* fout = new TFile("outtst.root", "RECREATE"); 
    TString fpath = "simc_root_files/"; 
    TString name = "C_rp1.root"; 
    TString fname = fpath + name; 
    TFile* fsim = new TFile(fname.Data(), "READ"); 

    TString tree_name = "h10"; 
    TTree* sim_tree = get_tree(fsim, tree_name); 

    gDirectory->GetName(); 
    // create and fill  the histogram 

    TH1F* hist = new TH1F("hist", "hist", 100, 8, 13); 
    sim_tree->Draw("mmnuc >> hist"); 

    // now creat a new file to save the histogram in 
    hist->SetDirectory(fout); 
    fout->cd();
   
    hist->Write(); 
    gDirectory->GetName(); 

    fsim->Close();
}