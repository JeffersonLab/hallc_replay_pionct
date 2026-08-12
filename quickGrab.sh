#!/bin/bash
# quickGrab.sh
# Written by Holly Szumila-Vance (hszumila@jlab.org)
#
# Usage: ./quickGrab.sh <run_number>
# Example: ./quickGrab.sh 29016

if [ -z "$1" ]; then
    echo "Usage: $0 <run_number>"
    exit 1
fi

RUNNUM="$1"

# Run number format check: expects exactly 5 digits (e.g. 29016)
if ! [[ "$RUNNUM" =~ ^[0-9]{5}$ ]]; then
    echo "ERROR: Run number '$RUNNUM' does not look valid."
    echo "Expected a 5-digit run number (e.g. 29016)."
    exit 1
fi

filename="REPORT_OUTPUT/COIN/PRODUCTION/replay_coin_production_${RUNNUM}_-1.report"

if [ ! -f "$filename" ]; then
    echo "ERROR: File not found: $filename"
    exit 1
fi

echo "=================================================="
echo "Reading report file: $filename"
echo "Script by Holly Szumila-Vance (hszumila@jlab.org)"
echo "=================================================="
echo ""

# Helper: run the grep, and flag it clearly if nothing was found
grab() {
    local label="$1"
    local pattern="$2"
    local val
    val=$(grep -oP "$pattern" "$filename")
    echo "$label"
    if [ -z "$val" ]; then
        echo "NOT FOUND (pattern did not match in file)"
    else
        echo "$val"
    fi
}

grab "BCM2 with 1uA cut (mC)" '(?<=SHMS BCM2  Beam Cut Charge: )[0-9.]+'
grab "Number of events:" '(?<=Accepted HMS Triggers         : )[0-9.]+'
grab "pi+ track efficiency:" '(?<=HADRON SING FID TRACK EFFIC    :   )[0-9.]+'
grab "e- track efficiency:" '(?<=E SING FID TRACK EFFIC         :   )[0-9.]+'
grab "3/4 efficiency (SHMS 1st, HMS 2nd):" '(?<=3_of_4 EFF : )[0-9.]+'
grab "HMS Cer eff:" '(?<=Overall HGC Efficiency: )[0-9.]+'
grab "SHMS Cer eff:" '(?<=Overall HGC Efficiency:       )[0-9.]+'
