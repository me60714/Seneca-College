/*********************************************************************************
* WEB322 – Assignment 3
* I declare that this assignment is my own work in accordance with Seneca Academic Policy.
* No part of this assignment has been copied manually or electronically from any other source
* (including web sites) or distributed to other students.
*
* Name: Wei-Chih Kao Student ID: 15800190 Date: Oct. 16. 2021
*
* Online (Heroku) URL: https://salty-taiga-57980.herokuapp.com/

********************************************************************************/

const HTTP_PORT = process.env.PORT || 8080;
const express = require("express");
const path = require("path");
const app = express();
const bodyParser = require('body-parser');

app.use(bodyParser.urlencoded({extended: true}));
app.use(express.static("public"));
app.use(express.static("image"));


function onHttpStart() {
  console.log("Express http server listening on: " + HTTP_PORT);
}

app.get("/", (req, res) => {
    res.sendFile(path.join(__dirname, "/views/homepage.html"));
})
app.get("/homepage", function(req, res){
    res.sendFile(path.join(__dirname, "/views/homepage.html"));
})
app.get("/mealpackage", function(req, res){
    res.sendFile(path.join(__dirname, "/views/mealpackage.html"));
})
app.get("/registration", function(req, res){
    res.sendFile(path.join(__dirname, "/views/registration.html"));
})
app.get("/login", function(req, res){
    res.sendFile(path.join(__dirname, "/views/login.html"));
})
app.get("/main.css", function(req, res){
    res.sendFile(path.join(__dirname, "/public/main.css"));
})

app.post("/registration", (req, res) => {
    res.sendFile(path.join(__dirname, "/views/dashboardpage.html"));
})

app.listen(HTTP_PORT, onHttpStart);