document.addEventListener('DOMContentLoaded', () => {
  
    const skills = [
        {name: "Guitar Lessons", type: "Music", description: "Learn the basics of guitar."},
        {name: "Math Tutoring", type: "Academics", description: "Help with high school math topics."},
        {name: "Cooking Basics", type: "Cooking", description: "Learn simple and delicious recipes."},
    ];
    function populateSkills() {
        const skillsList = document.querySelector('.skills-list');
        skills.forEach(skill => {
            const skillItem = document.createElement('div');
            skillItem.className = 'skill-item';
            skillItem.innerHTML = `
                <h3>${skill.name}</h3>
                <p><strong>Type:</strong> ${skill.type}</p>
                <p>${skill.description}</p>
                <button class="connect-btn">Connect</button>
            `;
            skillsList.appendChild(skillItem);
        });
    }

    populateSkills();
});
