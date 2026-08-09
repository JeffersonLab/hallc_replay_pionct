#include "stree.h"
#include "range.h"
#include <string> 
void createMM(){

    double H_norm[]  {0.529333E+08  ,0.698070E+08 , 0.901831E+08 ,0.107940E+09   };
    double LD2_norm[]  {0.439124E+08  , 0.574093E+08, 0.720899E+08  , 0.830087E+08 };
    double C_norm[] {0.728296E+07 , 0.932229E+07 , 0.112390E+08  , 0.126556E+08 };
    double Cu_norm[]  {0.630032E+06, 0.803934E+06, 0.963260E+06  ,  0.108405E+07 }; 
    range<float> trgRange[4] = {{0.8, 1.4}, {1.8, 3.2}, {11, 13.2}, {58, 61}};

    double normFacs[4][4] = {
        {0.529333E+08  ,0.698070E+08 , 0.901831E+08 ,0.107940E+09   }, 
        {0.439124E+08  , 0.574093E+08, 0.720899E+08  , 0.830087E+08 }, 
        {0.728296E+07 , 0.932229E+07 , 0.112390E+08  , 0.126556E+08 }, 
        {0.630032E+06, 0.803934E+06, 0.963260E+06  ,  0.108405E+07 }
    };
    // parse together simc root files names from target name 
    TString trg[4] = {"H", "ld2", "C", "Cu"}; 
    TString suff[4] = {"rp1","rp2", "rp3", "rp4" }; 
    TString QVals[4] = {"8.5", "7.5", "6.5", "5"};
    TH1F* hists[4][4]= {nullptr}; 
    TFile* fsim[4][4] ={nullptr}; 
    TFile* fout = new TFile("MMhists.root", "RECREATE"); 
    TString root_dir = "simc_root_files/"; 

    // now have a for loop of 16 iterations, for each iteration open the root file, and get the MM histogram and save it in a root file. 
    for (int i = 0 ; i < 4; ++i) // target
    { 

        for (int j = 0; j < 4; ++j) // Q2 values
        {
             // get file 
             // get tree 
              fsim[i][j] = new TFile(root_dir + Form("%s_%s.root", trg[i].Data(), suff[j].Data()), "READ");
            
            
              TTree* fsim_tree = get_tree(fsim[i][j], "h10"); 


            hists[i][j] = new TH1F(Form("%s_%s", trg[i].Data(), QVals[j].Data()), Form("%s - Q2 = %s", trg[i].Data(), QVals[j].Data()),
             400, trgRange[i].GetMin(), trgRange[i].GetMax());
             // now need to loop over the entries of the tree 

             Long64_t numEntries = fsim_tree->GetEntries();
             for (Long64_t k = 0; k < numEntries; ++k)
             {
                fsim_tree->GetEntry(k); 
                double xathgcer = ssxfp + 156.27 * ssxpfp;
                double yathgcer = ssyfp + 156.27 * ssypfp;
        
                bool central_hole       = (pow(yathgcer-1.33,2) + pow(xathgcer-0.83,2) >= pow(6.0,2));
                bool right_or_left_of_hole = ((yathgcer > 1.33 && (xathgcer < 0. || xathgcer > 3.0)) ||
                                      (yathgcer < 1.33 && (xathgcer < 0. || xathgcer > 3.0)));
                bool remove_region      = central_hole && right_or_left_of_hole;
                if (remove_region) {
             //hist->Fill(mmnuc, Weight * normFac / eventNum);
                hists[i][j]->Fill(mmnuc, Weight * normFacs[i][j] / 50000); 

                 }
                
                
             }
            hists[i][j]->SetDirectory(fout); 
            fout->cd(); 
            hists[i][j]->SetName(Form("%s_%s", trg[i].Data(), QVals[j].Data())); 
            hists[i][j]->Write(Form("%s_%s", trg[i].Data(), QVals[j].Data()), TObject::kOverwrite);
            fsim[i][j]->Close(); 

        }
    }

    


}