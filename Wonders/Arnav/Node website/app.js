const express = require('express');
const mongoose = require('mongoose');
const bodyParser = require('body-parser');
const path = require('path'); // Add path module
// Create Express ap
const app = express();
app.use(bodyParser.urlencoded({ extended: true }));
app.set('view engine', 'ejs');
// Serve static files from the 'public' directory
app.use(express.static(path.join(__dirname, 'public')));
// Connect to MongoDB Atlas
mongoose.connect('mongodb+srv://arnav9368543702:passkey=00@cluster0.erp1gx4.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0', {
  useNewUrlParser: true,
  useUnifiedTopology: true
}).then(() => {
  console.log('Connected to MongoDB Atlas');
}).catch((err) => {
  console.error('Error connecting to MongoDB Atlas:', err.message);
});
// Define Mongoose schema and model
const userSchema = new mongoose.Schema({
  email: String,
  password: String
});
const User = mongoose.model('User', userSchema);
// Routes
app.get('/', (req, res) => {
  res.render('index');
});
app.post('/users', async (req, res) => {
  const { email, password } = req.body;
  try {
    // Check if user exists
    const existingUser = await User.findOne({ email });
    if (existingUser) {
      console.log("User already exists");
      res.redirect('/login.html'); // Redirect to login page if user exists
    } else {
      // If user does not exist, save new user
      const newUser = new User(req.body);
      await newUser.save();
      console.log("User added");
      res.redirect('/index.html');
    }
  } catch (err) {
    console.error('Error saving user:', err.message);
    res.redirect('/');
  }
}
        );
app.post('/login', async (req, res) => {
  const { email, password } = req.body;
  try {
    // Check if user exists
    const existingUser = await User.findOne({ email, password });
    if (existingUser) {
      console.log("User logged in");
      res.redirect('/index.html'); // Redirect to index page upon successful login
    } else {
      // If user does not exist, redirect to signup page with an alert
      console.log("User not found");
      res.redirect('/signup.html');
    }
  } catch (err) {
    console.error('Error logging in:', err.message);
    res.redirect('/');
  }
});
// Start the server
const PORT = process.env.PORT || 4044;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});



