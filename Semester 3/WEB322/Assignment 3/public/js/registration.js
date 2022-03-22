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
let submitBtn = document.querySelector('#submit');
let regForm = document.querySelector('#form-registration'); 

submitBtn.onclick = (event) => {
  form.classList.add('was-validated');
};


regForm.phone.oninput = (event) => {    
    let phone = regForm.phone.value;
    let regex = /^((\(\d{3}\))|(\d{3}))\s?\d{3}[\s-]?\d{4}$/;
    if (regex.test(phone))
    {
        regForm.phone.setCustomValidity('');
    }
    else
    {
        regForm.phone.setCustomValidity('Please enter a valid phone number.');
    }
}

regForm.email.oninput = (event) => {    
    let email = regForm.email.value;
    let regex = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;

    if (regex.test(email))
    {
        regForm.email.setCustomValidity('');
    }
    else
    {
        regForm.email.setCustomValidity('Please enter a valid email.');
    }
}

