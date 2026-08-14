#include <iostream> 

void cprYield()
{
    TFile* fsim = new TFile("simHists.root", "READ"); 
    TH1F* hist = (TH1F*)fsim->Get("Cu_8.5_MM"); 
    std::cout << "yield is: " << hist->Integral() << '\n'; 
}