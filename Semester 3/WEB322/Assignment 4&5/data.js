const express = require("express");
const app = express();
const multer = require("multer");
const Sequelize = require('sequelize');

var sequelize = new Sequelize("df8ijeqq5h5v4m", "ibdkliioisbxso", "873420a20a081348d583efb90afacd1c91e492267825de36aa79ed3ce9c925ab",{
    host: "ec2-54-92-230-7.compute-1.amazonaws.com",
    dialect: 'postgres',
    port: 5432,
    dialectOptions: {
        ssl: { rejectUnauthorized: false }
    },
    query: { raw: true }
});

module.exports = {
    initialize: function() {
        return new Promise(function (resolve, reject) {
            sequelize.sync().then(() => {
                resolve();
            }).catch((err)=> {
                reject(err);
            })
        });
    }
}

const storage = multer.diskStorage({
  destination: "./public/photos/",
  filename: function (req, file, cb) {
    // we write the filename as the current date down to the millisecond
    // in a large web service this would possibly cause a problem if two people
    // uploaded an image at the exact same time. A better way would be to use GUID's for filenames.
    // this is a simple example.
    cb(null, Date.now() + path.extname(file.originalname));
  }
});
var mealsData = sequelize.define('mealsData', {
  // name, username, email, password, photo
  name: Sequelize.STRING,
  price: Sequelize.STRING,
  description: Sequelize.STRING,
  category: Sequelize.STRING,
  number: Sequelize.STRING,
  photo: Sequelize.STRING
});


const upload = multer({ storage: storage });

app.use(express.static("./public/"));


  app.get("/", (req, res) => {
    mealsData.findAll({
        order: ["id"]
    }).then((data) => {
        res.render("mealpackage", {
        data: data,
        layout: false
        });
    });
});


app.post("/addMeal", upload.single("photo"), (req, res) => {
  mealsData.create({
    name: req.body.name,
    price: req.body.price,
    description: req.body.description,
    category: req.body.category,
    number: req.body.number,
    photo: req.body.photo
  }).then(() => {
    console.log("successfully created a new meal");
    res.redirect("/");
});
});


app.post("/deleteMeal", upload.single("photo"), (req, res) => {
  mealsData.destroy({
    where: { id: req.body.id }
  }).then(() => {
    console.log("successfully removed meal: " + req.body.id);
    res.redirect("/");
  });
  
});

app.post("/updateMeal", upload.single("photo"), (req, res) => {
  mealsData.update({
    name: req.body.name,
    price: req.body.price,
    description: req.body.description,
    category: req.body.category,
    number: req.body.number,
  }, {
    where: { id: req.body.id }
  }).then(() => {
    console.log("successfully updated meal: " + req.body.id);
    res.redirect("/");
  });
    
});

