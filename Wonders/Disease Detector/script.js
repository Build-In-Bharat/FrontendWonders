// Placeholder dataset with sample data
let diseaseDataset = [
  { disease: "Common Cold", symptoms: ["cough", "sore throat", "runny nose"] },
  { disease: "Flu", symptoms: ["fever", "cough", "body ache", "fatigue"] },
  { disease: "COVID-19", symptoms: ["fever", "cough", "difficulty breathing", "loss of taste"] },
  { disease: "Malaria", symptoms: ["fever", "chills", "headache", "sweating"] },
  { disease: "Migraine", symptoms: ["headache", "nausea", "sensitivity to light", "sensitivity to sound"] }
];

// Function to detect disease based on symptoms
function detectDisease() {
  const symptomsInput = document.getElementById("symptoms").value.trim();
  const inputSymptoms = symptomsInput.split(",").map(symptom => symptom.trim().toLowerCase());

  let possibleDiseases = [];
  
  // Matching logic
  diseaseDataset.forEach(diseaseData => {
    const matchedSymptoms = diseaseData.symptoms.filter(symptom => inputSymptoms.includes(symptom));

    if (matchedSymptoms.length > 0) {
      possibleDiseases.push(`${diseaseData.disease} (Matched Symptoms: ${matchedSymptoms.join(", ")})`);
    }
  });

  const resultDiv = document.getElementById("result");

  // Display Results
  if (possibleDiseases.length > 0) {
    resultDiv.innerHTML = `<b>Possible Diseases:</b> <br> ${possibleDiseases.join("<br>")}`;
  } else {
    resultDiv.innerHTML = "No matching disease found. Please check symptoms.";
  }

  // Animation Effect
  resultDiv.classList.add("show");
}
