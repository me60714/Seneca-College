/*********************************************************************************
*  WEB322 – Assignment 1
*  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.  
*  No part of this assignment has been copied manually or electronically from any other source
*  (including web sites) or distributed to other students.
* 
*  Name: Wei-Chih Kao Student ID: 15800190 Date: Sep. 12. 2021
*
*  Online (Heroku) URL: https://damp-reaches-00568.herokuapp.com/
*
********************************************************************************/ 

var HTTP_PORT = process.env.PORT || 8080;
var express = require("express");
var app = express();

// setup a 'route' to listen on the default url path
app.get("/", (req, res) => {
    res.send("Wei-Chih Kao --- 158000190");
});

// setup http server to listen on HTTP_PORT
app.listen(HTTP_PORT);