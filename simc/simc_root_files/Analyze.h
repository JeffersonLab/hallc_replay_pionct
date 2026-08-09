//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sat Jun 20 22:54:42 2026 by ROOT version 6.36.06
// from TTree h10/h10
// found on file: C_rp1.root
//////////////////////////////////////////////////////////

#ifndef Analyze_h
#define Analyze_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector


class Analyze : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderValue<Float_t> hsdelta = {fReader, "hsdelta"};
   TTreeReaderValue<Float_t> hsyptar = {fReader, "hsyptar"};
   TTreeReaderValue<Float_t> hsxptar = {fReader, "hsxptar"};
   TTreeReaderValue<Float_t> hsytar = {fReader, "hsytar"};
   TTreeReaderValue<Float_t> hsxfp = {fReader, "hsxfp"};
   TTreeReaderValue<Float_t> hsxpfp = {fReader, "hsxpfp"};
   TTreeReaderValue<Float_t> hsyfp = {fReader, "hsyfp"};
   TTreeReaderValue<Float_t> hsypfp = {fReader, "hsypfp"};
   TTreeReaderValue<Float_t> hsdeltai = {fReader, "hsdeltai"};
   TTreeReaderValue<Float_t> hsyptari = {fReader, "hsyptari"};
   TTreeReaderValue<Float_t> hsxptari = {fReader, "hsxptari"};
   TTreeReaderValue<Float_t> hsytari = {fReader, "hsytari"};
   TTreeReaderValue<Float_t> ssdelta = {fReader, "ssdelta"};
   TTreeReaderValue<Float_t> ssyptar = {fReader, "ssyptar"};
   TTreeReaderValue<Float_t> ssxptar = {fReader, "ssxptar"};
   TTreeReaderValue<Float_t> ssytar = {fReader, "ssytar"};
   TTreeReaderValue<Float_t> ssxfp = {fReader, "ssxfp"};
   TTreeReaderValue<Float_t> ssxpfp = {fReader, "ssxpfp"};
   TTreeReaderValue<Float_t> ssyfp = {fReader, "ssyfp"};
   TTreeReaderValue<Float_t> ssypfp = {fReader, "ssypfp"};
   TTreeReaderValue<Float_t> ssdeltai = {fReader, "ssdeltai"};
   TTreeReaderValue<Float_t> ssyptari = {fReader, "ssyptari"};
   TTreeReaderValue<Float_t> ssxptari = {fReader, "ssxptari"};
   TTreeReaderValue<Float_t> ssytari = {fReader, "ssytari"};
   TTreeReaderValue<Float_t> q = {fReader, "q"};
   TTreeReaderValue<Float_t> nu = {fReader, "nu"};
   TTreeReaderValue<Float_t> Q2 = {fReader, "Q2"};
   TTreeReaderValue<Float_t> W = {fReader, "W"};
   TTreeReaderValue<Float_t> epsilon = {fReader, "epsilon"};
   TTreeReaderValue<Float_t> Em = {fReader, "Em"};
   TTreeReaderValue<Float_t> Pm = {fReader, "Pm"};
   TTreeReaderValue<Float_t> thetapq = {fReader, "thetapq"};
   TTreeReaderValue<Float_t> phipq = {fReader, "phipq"};
   TTreeReaderValue<Float_t> missmass = {fReader, "missmass"};
   TTreeReaderValue<Float_t> mmnuc = {fReader, "mmnuc"};
   TTreeReaderValue<Float_t> phad = {fReader, "phad"};
   TTreeReaderValue<Float_t> t = {fReader, "t"};
   TTreeReaderValue<Float_t> pmpar = {fReader, "pmpar"};
   TTreeReaderValue<Float_t> pmper = {fReader, "pmper"};
   TTreeReaderValue<Float_t> pmoop = {fReader, "pmoop"};
   TTreeReaderValue<Float_t> fry = {fReader, "fry"};
   TTreeReaderValue<Float_t> radphot = {fReader, "radphot"};
   TTreeReaderValue<Float_t> pfermi = {fReader, "pfermi"};
   TTreeReaderValue<Float_t> siglab = {fReader, "siglab"};
   TTreeReaderValue<Float_t> sigcm = {fReader, "sigcm"};
   TTreeReaderValue<Float_t> Weight = {fReader, "Weight"};
   TTreeReaderValue<Float_t> decdist = {fReader, "decdist"};
   TTreeReaderValue<Float_t> Mhadron = {fReader, "Mhadron"};
   TTreeReaderValue<Float_t> pdotqhat = {fReader, "pdotqhat"};
   TTreeReaderValue<Float_t> Q2i = {fReader, "Q2i"};
   TTreeReaderValue<Float_t> Wi = {fReader, "Wi"};
   TTreeReaderValue<Float_t> ti = {fReader, "ti"};
   TTreeReaderValue<Float_t> phipqi = {fReader, "phipqi"};


   Analyze(TTree * /*tree*/ =0) { }
   ~Analyze() override { }
   Int_t   Version() const override { return 2; }
   void    Begin(TTree *tree) override;
   void    SlaveBegin(TTree *tree) override;
   void    Init(TTree *tree) override;
   bool    Notify() override;
   bool    Process(Long64_t entry) override;
   Int_t   GetEntry(Long64_t entry, Int_t getall = 0) override { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   void    SetOption(const char *option) override { fOption = option; }
   void    SetObject(TObject *obj) override { fObject = obj; }
   void    SetInputList(TList *input) override { fInput = input; }
   TList  *GetOutputList() const override { return fOutput; }
   void    SlaveTerminate() override;
   void    Terminate() override;

   ClassDefOverride(Analyze,0);

};

#endif

#ifdef Analyze_cxx
void Analyze::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

bool Analyze::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return true;
}


#endif // #ifdef Analyze_cxx
