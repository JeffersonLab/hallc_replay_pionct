import pandas as pd
import os
import numpy as np

# =================================================================================
# --- 1. INPUT CONFIGURATION ---
# =================================================================================
# File paths
BIGTABLE_PATH = "/home/cdaq/rsidis-2025/hallc_replay_rsidis/AUX_FILES/rsidis_bigtable_phaseII.csv"
OUTPUT_CSV = "boiling_correction_factors.csv"

# Current settings
CHOSEN_BCM = "BCM2"      # Choose which BCM to use (e.g., "BCM2", "BCM4A")
CURRENT_OFFSET = 0.039   # offset I in uA

# Boiling slopes (yield change per 100 uA)
LH2_SLOPE = -3.36
LD2_SLOPE = -1.98

# =================================================================================
# --- 2. MAIN ANALYSIS ---
# =================================================================================
def calculate_corrections():
    print(f"Loading BigTable from: {BIGTABLE_PATH}")
    
    try:
        df = pd.read_csv(BIGTABLE_PATH)
    except FileNotFoundError:
        print(f"Error: BigTable not found at {BIGTABLE_PATH}")
        return

    bcm_col = f"{CHOSEN_BCM}_I"
    
    # Ensure required columns exist in the dataframe
    required_cols = ["run", "target", bcm_col]
    for col in required_cols:
        if col not in df.columns:
            print(f"Error: Required column '{col}' not found in BigTable.")
            return

    results = []

    print(f"Calculating correction factors using {bcm_col}...")
    
    # Iterate through the runs to calculate corrections
    for _, row in df.iterrows():
        run = int(row["run"]) if pd.notna(row["run"]) else -999
        target = row["target"]
        curr = row[bcm_col]

        # Handle missing or invalid current data
        if pd.isna(curr) or curr <= 0:
            offset_corr = np.nan
            boil_corr = np.nan
        else:
            # 1. Current Offset Correction
            offset_corr = 1.0 / (1.0 + (CURRENT_OFFSET / curr))

            # 2. Target Boiling Correction
            if target == "LH2":
                boil_corr = 1.0 / (1.0 + (LH2_SLOPE / 100.0) * (curr / 100.0))
            elif target == "LD2":
                boil_corr = 1.0 / (1.0 + (LD2_SLOPE / 100.0) * (curr / 100.0))
            else:
                # Solid targets or DUMMY get a correction factor of 1.0
                boil_corr = 1.0

        # Append to results list
        results.append({
            "run": run,
            "target": target,
            "bcm_used": bcm_col,
            "current_offset_correction": offset_corr,
            "boiling_correction": boil_corr
        })

    # =================================================================================
    # --- 3. EXPORT DATA ---
    # =================================================================================
    res_df = pd.DataFrame(results)
    res_df.to_csv(OUTPUT_CSV, index=False, float_format='%.3f', na_rep='-999')
    print(f"Successfully processed {len(res_df)} runs.")
    print(f"Output saved to: {OUTPUT_CSV}")

if __name__ == "__main__":
    calculate_corrections()
