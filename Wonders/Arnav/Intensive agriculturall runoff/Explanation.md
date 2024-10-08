# Explanation of above turing machine by an example

## S=|  ∐ | Res | O2  | Pest | Nitro | Phos|  ∐  |

### [  ∐  denotes blank]   

- Initialization (Q0):
- Start in state Q0.
- Move the tape head right until a symbol is encountered.
- Detect Pollutants (Q1):
- Encountered 'S' (sample), transition to state Q1.
- Scan the water sample for pollutants.
- Detects 'Res' (residue), 'Pest' (pesticides), 'Nitro' (nitrogen), and 'Phos' (phosphorus).
- Since pollutants are detected, continue scanning.
- Assess Water Quality (Q2):
- Continue scanning for additional pollutants or checking for oxygen levels.
- Encounters 'O2' (oxygen).
- Since oxygen is present, transition to state Q3 for confirmation.
- Confirmation (Q3):
- Confirm the presence of pollutants.
- Transition to state Q5 since pollutants are confirmed.
- Accept State (Q5):
- Pollution is detected, so the Turing machine enters the accept state Q5.
