// Select elements
const recipeForm = document.getElementById("recipe-form");
const recipeList = document.getElementById("recipe-list");

document.addEventListener("DOMContentLoaded", displayRecipes);

// Handle form submission
recipeForm.addEventListener("submit", function (event) {
  event.preventDefault();

  // Get input values
  const title = document.getElementById("recipe-name").value;
  const ingredients = document.getElementById("ingredients").value;
  const instructions = document.getElementById("instructions").value;
  const recipe = { title, ingredients, instructions };
  saveRecipe(recipe);
  recipeForm.reset();
  displayRecipes();
});
function saveRecipe(recipe) {
  const recipes = JSON.parse(localStorage.getItem("recipes")) || [];
  recipes.push(recipe);
  localStorage.setItem("recipes", JSON.stringify(recipes));
}
// Display recipes from local storage
function displayRecipes() {
  const recipes = JSON.parse(localStorage.getItem("recipes")) || [];
  recipeList.innerHTML = "";

  recipes.forEach((recipe, index) => {
    const recipeCard = document.createElement("div");
    recipeCard.className = "recipe-card";
    recipeCard.innerHTML = `
      <h2>${recipe.title}</h2>
      <p><strong>Ingredients:</strong> ${recipe.ingredients}</p>
      <p><strong>Instructions:</strong> ${recipe.instructions}</p>
      <button class="delete-button" onclick="deleteRecipe(${index})">Delete</button>
    `;
    recipeList.appendChild(recipeCard);
  });
}

// Delete recipe by index
function deleteRecipe(index) {
  const recipes = JSON.parse(localStorage.getItem("recipes")) || [];
  recipes.splice(index, 1);
  localStorage.setItem("recipes", JSON.stringify(recipes));
  displayRecipes();
}
