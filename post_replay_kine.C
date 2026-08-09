#include <iostream>
#include "TString.h"
#include "THaAnalyzer.h"
#include "THaEvent.h"
#include "THaPhysicsModule.h"
#include "THcPrimaryKine.h"

void post_replay_kine(Int_t run_number = 25544) {
  
  // =========================================================================
  // 1. Initialize and Setup Parameter Database (gHcParms)
  // =========================================================================
  cout << "Reading target mass from database..." << endl;
  
  // Set DB and Parameter file directories
  //gHcParms->AddString("g_ctp_database_filename", "DBASE/COIN/standard.database");
  //gHcParms->Load("PARAM/HMS/GEN/h_fadc_debug.param"); // Adjust as needed for your DB
  //gHcParms->Load("PARAM/GEN/gtarget.param");          // Loads gtarget_mass

  gHcParms->Load("DBASE/COIN/standard.kinematics");
  
  // Extract target mass from gHcParms (default to proton if missing)
  Double_t target_mass = 0.938272; // Default (GeV/c^2)
  if (gHcParms->FindObject("gtarget_mass")) {
    target_mass = *(Double_t*)gHcParms->FindObject("gtarget_mass");
    cout << "--> Loaded target mass from DB: " << target_mass << " GeV/c^2" << endl;
  } else {
    cout << "--> Warning: gtarget_mass not found in DB! Defaulting to proton mass." << endl;
  }

  Double_t particle_mass = 0.000510998; // Electron mass in GeV/c^2

  // =========================================================================
  // 2. Setup the Hall C Physics Kinematics Module
  // =========================================================================
  // "H" denotes the HMS spectrometer prefix
  THcPrimaryKine* H_kin = new THcPrimaryKine("H.kin.primary", "HMS Kinematics", "H", target_mass, particle_mass);
  gHaPhysics->Add(H_kin);

  // =========================================================================
  // 3. Configure Input/Output and Run the Analyzer
  // =========================================================================
  // File naming conventions
  TString in_file  = Form("ROOTfiles/coin_replay_production_%d_-1.root", run_number);
  TString out_file = Form("ROOTfiles/hms_replayed_kine_%d.root", run_number);

  cout << "Processing input file: " << in_file << endl;
  cout << "Generating output file: " << out_file << endl;

  // Point the analyzer to the existing ROOT file as input
  THaAnalyzer* analyzer = new THaAnalyzer();
  
  // Add output variables to the output tree
  TString def_file = "DEF-files/COIN/PRODUCTION/hms_kine.def"; 
  analyzer->SetOdefFile(def_file);
  
  // Run over the pre-replayed ROOT file
  analyzer->SetEvent( new THaEvent() );
  analyzer->SetOutFile(out_file);


   // Define the run(s) that we want to analyze.                                                                                     
  // We just set up one, but this could be many.                                                                                    
  THcRun* run = new THcRun( pathList, Form(RunFileNamePattern, RunNumber) );                                                        
                                                                                                                                    
  // Set to read in Hall C run database parameters                                                                                  
  run->SetRunParamClass("THcRunParameters");                                                                                        
                                                                                                                                    
  // Eventually need to learn to skip over, or properly analyze the pedestal events                                                 
  run->SetEventRange(1, MaxEvent); // Physics Event number, does not include scaler or control events.                              
  run->SetNscan(1);                                                                                                                 
  run->SetDataRequired(0x7);                                                                                                        
  run->Print(); 
  
  // Process the replayed run (set number of events to process, e.g., -1 for all)
  analyzer->Process(run);

  // Cleanup memory
  delete analyzer;
  cout << "Post-replay kinematics processing completed successfully!" << endl;
}
