#include "stree.h"
void getsidis()
{
    TFile* fout = new TFile("simHists.root", "UPDATE"); 
    // 1- open root file 
    TFile* fsim = new TFile("simc_root_files/H_27916.root", "READ"); 
    TString tree_name = "h10"; 
    TTree* simTree = get_tree(fsim, tree_name); 
    double normFac = 0.193217E+08   ; 

    Long64_t numEntries = simTree->GetEntries(); 
    TH1F* MMhist = new TH1F("H_4.3_MM", "LH2 - Q2 = 4.3", 400, 0.8, 2);
    TH1F* Qhist = new TH1F("H_4.3_Q2", "LH2 - Q2 = 4.3", 400, 0.5, 6); 
    TH1F* Whist = new TH1F("H_4.3_W", "LH2 - Q2 = 4.3", 400 , 1, 5); 
    for (Long64_t i{0} ; i < numEntries ; ++i)
    {
    simTree->GetEntry(i);

    double xathgcer = ssxfp + 156.27 * ssxpfp;
    double yathgcer = ssyfp + 156.27 * ssypfp;
        
    bool central_hole       = (pow(yathgcer-1.33,2) + pow(xathgcer-0.83,2) >= pow(6.0,2));
    bool right_or_left_of_hole = ((yathgcer > 1.33 && (xathgcer < 0. || xathgcer > 3.0)) ||
                                      (yathgcer < 1.33 && (xathgcer < 0. || xathgcer > 3.0)));
    bool remove_region      = central_hole && right_or_left_of_hole;
        
    if (remove_region) {

            MMhist->Fill(mmnuc, Weight* normFac / 50000); 
            Qhist->Fill(Q2, Weight* normFac / 50000); 
            Whist->Fill(W, Weight* normFac / 50000); 
    }
    }
    MMhist->SetDirectory(fout);
    Qhist->SetDirectory(fout); 
    Whist->SetDirectory(fout);
    fout->cd();
    MMhist->Write(MMhist->GetName(), TObject::kOverwrite); 
    Qhist->Write(Qhist->GetName(), TObject::kOverwrite); 
    Whist->Write(Whist->GetName(), TObject::kOverwrite); 
    fsim->Close(); 



}