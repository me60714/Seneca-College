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

// An instance of our SimpleMap, created below when the window loads.
let map;

// Update the map to show markers for the set of observations
function updateMap(observations, map) {
  // Clear the current markers on the map (if any)
  map.clear();

  // TODO: call the Simple Map's addObservation method for every one
  // of the observations in order to add markers to the map.
  observations.forEach((observation) => {
    map.addObservation(observation);
  });
}

function updateCards(observations) {
  clearAllCards();

  observations.forEach((observation) => {
    let card = buildCardForObservation(observation);
    addCard(card);
  });
}

function showAll() {
  const observations = getAllObservations();

  updateMap(observations, map);
  updateCards(observations);
  updateCardTitle(`All Species (${observations.length})`);
}

function showOnlyNative() {
  const observations = getAllObservations();
  const native = filterOnlyNative(observations);
  updateMap(native, map);
  updateCards(native);
  updateCardTitle(`Only Native Species (${native.length})`);
}

function showOnlyIntroduced() {
  const observations = getAllObservations();
  const introduced = filterOnlyIntroduced(observations);
  updateMap(introduced, map);
  updateCards(introduced);
  updateCardTitle(`Only Introduced Species (${introduced.length})`);
}

function start() {
  map = new SimpleMap("map-container", 43.7955, -79.3496);
  showAll();
  let all = document.querySelector("#show-all");
  all.addEventListener("click", function () {
    showAll();
  });

  let onlyNative = document.querySelector("#show-native");
  onlyNative.addEventListener("click", function () {
    showOnlyNative();
  });

  let onlyIntroduced = document.querySelector("#show-introduced");
  onlyIntroduced.addEventListener("click", function () {
    showOnlyIntroduced();
  });
}

start();
