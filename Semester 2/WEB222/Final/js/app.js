// * WEB222 – Final Assessment
// *
// * I declare that this assignment is my own work in accordance with
// * Seneca Academic Policy. No part of this assignment has been
// * copied manually or electronically from any other source
// * (including web sites) or distributed to other students.
// *
// * Please update the following with your information:
// *
// * Name: Wei-Chih Kao
// * Student ID: 158000190
// * Date: 2021.08.11

let form = document.querySelector('#appt-form');
let submitBtn = document.querySelector('#submit');
let resetBtn = document.querySelector('#reset');

submitBtn.onclick = (event) => {
  form.classList.add('was-validated');
};

resetBtn.onclick = (event) => {
  form.classList.remove('was-validated');
};

form.phone.oninput = (event) => {
  let phone = form.phone.value;
  let regex = /^((\(\d{3}\))|(\d{3}))\s?\d{3}[\s-]?\d{4}$/;
  if (regex.test(phone)){
    form.phone.setCustomValidity('');
  }else {
    form.phone.setCustomValidity('Please enter a valid phone number.');
  }
}

form["postal-code"].oninput = (event) => {
  let postalCode = form['postal-code'].value;
  let regex = /^[A-Za-z]\d[A-Za-z][\s-]?\d[A-Za-z]\d$/;
  if (regex.test(postalCode)){
    form['postal-code'].setCustomValidity('');
  }else {
    form['postal-code'].setCustomValidity('Please enter a valid postal code.');
  }
};

document.querySelector('#hiring').onclick = function(){
  hidden.type="number";
  hidden.placeholder = " Hourly Rate";
}

document.querySelector('#comment').onclick = function(){
  hidden.type="hidden";
}

document.querySelector('#question').onclick = function(){
  hidden.type="hidden";
}