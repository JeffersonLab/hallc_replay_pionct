#ifndef RECON_BRANCH_H_06_13
#define RECON_BRANCH_H_06_13
#include "TFile.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include <iostream>


// Declaration of leaves types
   Float_t         hsdelta;
   Float_t         hsyptar;
   Float_t         hsxptar;
   Float_t         hsytar;
   Float_t         hsxfp;
   Float_t         hsxpfp;
   Float_t         hsyfp;
   Float_t         hsypfp;
   Float_t         hsdeltai;
   Float_t         hsyptari;
   Float_t         hsxptari;
   Float_t         hsytari;
   Float_t         ssdelta;
   Float_t         ssyptar;
   Float_t         ssxptar;
   Float_t         ssytar;
   Float_t         ssxfp;
   Float_t         ssxpfp;
   Float_t         ssyfp;
   Float_t         ssypfp;
   Float_t         ssdeltai;
   Float_t         ssyptari;
   Float_t         ssxptari;
   Float_t         ssytari;
   Float_t         q;
   Float_t         nu;
   Float_t         Q2;
   Float_t         W;
   Float_t         epsilon;
   Float_t         Em;
   Float_t         Pm;
   Float_t         thetapq;
   Float_t         phipq;
   Float_t         missmass;
    Float_t         mmnuc;
   Float_t         phad;
   Float_t         t;
   Float_t         pmpar;
   Float_t         pmper;
   Float_t         pmoop;
   Float_t         fry;
   Float_t         radphot;
   Float_t         pfermi;
   Float_t         siglab;
   Float_t         sigcm;
   Float_t         Weight;
   Float_t         decdist;
   Float_t         Mhadron;
   Float_t         pdotqhat;
   Float_t         Q2i;
   Float_t         Wi;
   Float_t         ti;
   Float_t         phipqi;
    TFile* get_file(TString file_name)
    
    {
    TFile* file = new TFile(file_name, "read");
    if (!file || file->IsZombie()) {
        std::cout << "Error opening file: " << file_name << std::endl;
        return nullptr;
    }
    return file;
    }

    TTree *get_tree(TFile* file, TString tree_name)
    {
     if (!file) {
        std::cout << "Invalid file pointer." << std::endl;
        return nullptr;
    }
    TTree*   h10 = dynamic_cast<TTree*>(file->Get(tree_name));
    if (!  h10) {
        std::cout << "Error accessing TTree from file: " << std::endl;
        file->Close();
        return nullptr;
    }
        
   
      h10->SetBranchAddress("hsdelta",&hsdelta);
   h10->SetBranchAddress("hsyptar",&hsyptar);
   h10->SetBranchAddress("hsxptar",&hsxptar);
   h10->SetBranchAddress("hsytar",&hsytar);
   h10->SetBranchAddress("hsxfp",&hsxfp);
   h10->SetBranchAddress("hsxpfp",&hsxpfp);
   h10->SetBranchAddress("hsyfp",&hsyfp);
   h10->SetBranchAddress("hsypfp",&hsypfp);
   h10->SetBranchAddress("hsdeltai",&hsdeltai);
   h10->SetBranchAddress("hsyptari",&hsyptari);
   h10->SetBranchAddress("hsxptari",&hsxptari);
   h10->SetBranchAddress("hsytari",&hsytari);
   h10->SetBranchAddress("ssdelta",&ssdelta);
   h10->SetBranchAddress("ssyptar",&ssyptar);
   h10->SetBranchAddress("ssxptar",&ssxptar);
   h10->SetBranchAddress("ssytar",&ssytar);
   h10->SetBranchAddress("ssxfp",&ssxfp);
   h10->SetBranchAddress("ssxpfp",&ssxpfp);
   h10->SetBranchAddress("ssyfp",&ssyfp);
   h10->SetBranchAddress("ssypfp",&ssypfp);
   h10->SetBranchAddress("ssdeltai",&ssdeltai);
   h10->SetBranchAddress("ssyptari",&ssyptari);
   h10->SetBranchAddress("ssxptari",&ssxptari);
   h10->SetBranchAddress("ssytari",&ssytari);
   h10->SetBranchAddress("q",&q);
   h10->SetBranchAddress("nu",&nu);
   h10->SetBranchAddress("Q2",&Q2);
   h10->SetBranchAddress("W",&W);
   h10->SetBranchAddress("epsilon",&epsilon);
   h10->SetBranchAddress("Em",&Em);
   h10->SetBranchAddress("Pm",&Pm);
   h10->SetBranchAddress("thetapq",&thetapq);
   h10->SetBranchAddress("phipq",&phipq);
   h10->SetBranchAddress("missmass",&missmass);
    h10->SetBranchAddress("mmnuc",&mmnuc);
    h10->SetBranchAddress("phad",&phad);
   h10->SetBranchAddress("t",&t);
   h10->SetBranchAddress("pmpar",&pmpar);
   h10->SetBranchAddress("pmper",&pmper);
   h10->SetBranchAddress("pmoop",&pmoop);
   h10->SetBranchAddress("fry",&fry);
   h10->SetBranchAddress("radphot",&radphot);
   h10->SetBranchAddress("pfermi",&pfermi);
   h10->SetBranchAddress("siglab",&siglab);
   h10->SetBranchAddress("sigcm",&sigcm);
   h10->SetBranchAddress("Weight",&Weight);
   h10->SetBranchAddress("decdist",&decdist);
   h10->SetBranchAddress("Mhadron",&Mhadron);
   h10->SetBranchAddress("pdotqhat",&pdotqhat);
   h10->SetBranchAddress("Q2i",&Q2i);
   h10->SetBranchAddress("Wi",&Wi);
   h10->SetBranchAddress("ti",&ti);
   h10->SetBranchAddress("phipqi",&phipqi);
    
    return h10;
}
#endif