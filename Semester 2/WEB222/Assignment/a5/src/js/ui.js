/**
 * WEB222 – Assignment 05
 *
 * I declare that this assignment is my own work in accordance with
 * Seneca Academic Policy. No part of this assignment has been
 * copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Please update the following with your information:
 *
 *      Name: Wei-Chih Kao
 *      Student ID: 158000190
 *      Date: 2021.08.05
 *
 */

function updateCardTitle(title) {
  let titleText = document.createTextNode(title);
  let newTitle = document.querySelector("#card-title span");
  newTitle.innerHTML = null;
  newTitle.appendChild(titleText);
  return newTitle;
}

function addCard(card) {
  let newCard = document.querySelector("#observation-cards");
  // newCard.id = "cards";
  newCard.appendChild(card);
  return newCard;
}

function clearAllCards() {
  let cardContent = document.getElementById("observation-cards");
  while (cardContent.firstChild) {
    cardContent.removeChild(cardContent.firstChild);
  }
  return cardContent;
}

function createCard(id) {
  let card = document.createElement("div");
  card.id = id;
  return card;
}

function buildCardForObservation(observation) {
  let div = document.createElement("div");
  div.className = "card";
  div.id = observation.id;
  let cardImg_ = cardImg(observation.photoUrl);
  let cardBody_ = cardBody(
    observation.name,
    observation.date,
    observation.uri,
    observation.wikipediaUrl
  );
  let cardIcons_ = cardIcons(
    observation.isNative,
    observation.isIntroduced,
    observation.isEndangered,
    observation.isThreatened
  );

  div.appendChild(cardImg_);
  div.appendChild(cardBody_);
  div.appendChild(cardIcons_);

  return div;
}

function cardImg(url) {
  url = url.replace(/square/i, "medium");
  let div = document.createElement("div");
  div.className = "card-img";
  div.style.backgroundImage = `url(${url})`;

  return div;
}

function formatDate(date) {
  var d = new Date(date),
    month = "" + (d.getMonth() + 1),
    day = "" + d.getDate(),
    year = d.getFullYear();
  if (month.length < 2) month = "0" + month;
  if (day.length < 2) day = "0" + day;
  return [year, month, day].join("-");
}

function cardBody(name, date, uri, wikipediaUrl) {
  let div = document.createElement("div");
  div.className = "card-body";
  let h3Name = document.createElement("h3");
  let h4Date = document.createElement("h4");
  let nameUrl = document.createElement("a");
  let dateUrl = document.createElement("a");
  nameUrl.href = wikipediaUrl;
  dateUrl.href = uri;
  nameUrl.innerText = name;
  date = formatDate(date);
  dateUrl.innerText = date;
  h3Name.appendChild(nameUrl);
  h4Date.appendChild(dateUrl);
  div.appendChild(h3Name);
  div.appendChild(h4Date);

  return div;
}

function cardIcons(isNative, isIntroduced, isThreatened, isEndangered) {
  let div = document.createElement("div");
  div.className = "card-icons";
  if (isNative) {
    let nativeIcon = document.createElement("i");
    nativeIcon.className = "fas fa-leaf";
    nativeIcon.title = "Native";
    div.appendChild(nativeIcon);
  }

  if (isIntroduced) {
    let introducedIcon = document.createElement("i");
    introducedIcon.className = "fas fa-frog";
    introducedIcon.title = "Introduced";
    div.appendChild(introducedIcon);
  }

  if (isThreatened) {
    let threatenedIcon = document.createElement("i");
    threatenedIcon.className = "fas fa-radiation-alt";
    threatenedIcon.title = "Threatened";
    div.appendChild(threatenedIcon);
  }

  if (isEndangered) {
    let endangeredIcon = document.createElement("i");
    endangeredIcon.className = "fas fa-skull-crossbones";
    endangeredIcon.title = "Endangered";
    div.appendChild(endangeredIcon);
  }

  return div;
}
