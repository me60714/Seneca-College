/**
 * WEB222 – Assignment 04
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
 *      Date: 2021.07.23
 *
 */

// An iNaturalist observation Object contains a tremendous amount of data, much of
// it not useful in our current program. We need to transform these Observation
// objects into a new format that matches our needs.
//
// Here's a simplified version of the current structure of an observation Object
// (see src/data.js for a complete example of what it looks like). Many of the
// properties and values have been removed to highlight the ones we do
// care about:
//
// {
//   id: 67868131,
//   uri: "https://www.inaturalist.org/observations/67868131",
//   geojson: {
//     coordinates: [ -79.3565522733, 43.798774894 ],
//     type: "Point"
//   },
//   created_at: "2021-01-10T09:51:48-10:00",
//   taxon: {
//     threatened: false,
//     introduced: false,
//     native: true,
//     name: "Ondatra zibethicus",
//     wikipedia_url: "http://en.wikipedia.org/wiki/Muskrat",
//     default_photo: {
//       square_url:
//         "https://static.inaturalist.org/photos/109319291/square.jpg?1609877680",
//       attribution: "(c) Stephen Garvey, all rights reserved",
//       flags: [],
//       medium_url:
//         "https://static.inaturalist.org/photos/109319291/medium.jpg?1609877680",
//       id: 109319291,
//       license_code: null,
//       original_dimensions: { width: 2048, height: 1365 },
//       url:
//         "https://static.inaturalist.org/photos/109319291/square.jpg?1609877680",
//     },
//     iconic_taxon_name: "Mammalia",
//     preferred_common_name: "Muskrat"
//   }
// },
//
// Here's the same data transformed into a simpler format we want to use:
//
// {
//   id: 67868131,
//   uri: "https://www.inaturalist.org/observations/67868131",
//   coords: [ -79.3565522733, 43.798774894 ],
//   date: Date Sun Jan 10 2021 14:51:48 GMT-0500 (Eastern Standard Time),
//   name: "Muskrat",
//   photoUrl: "https://static.inaturalist.org/photos/109319291/square.jpg?1609877680",
//   wikipediaUrl: "http://en.wikipedia.org/wiki/Muskrat",
//   isNative: true,
//   isIntroduced: false,
//   isEndangered: false,
//   isThreatened: false
// }

// Given a string, convert the first letter of each word in the
// string to a capital letter. For example, convert 'muskrat' to
// 'Muskrat', and 'bittersweet nightshade' to 'Bittersweet Nightshade'
function titleCase(s) {
  return s.slice(0, 1).toUpperCase() + s.slice(1);
}

// Given an Array of iNaturalist observation objects, transform the objects into
// our desired format, and return the new Array. For example:
//​
// [
//   {
//     id: 67868131,
//     uri: "https://www.inaturalist.org/observations/67868131",
//     coords: [ -79.3565522733, 43.798774894 ],
//     date: Date Sun Jan 10 2021 14:51:48 GMT-0500 (Eastern Standard Time),
//     name: "Muskrat",
//     photoUrl: "https://static.inaturalist.org/photos/109319291/square.jpg?1609877680",
//     wikipediaUrl: "http://en.wikipedia.org/wiki/Muskrat",
//     isNative: true,
//     isIntroduced: false,
//     isEndangered: false,
//     isThreatened: false
//   },
//   ...
// ]
//
// Things to note in your solution:
//
// - id: use the same value unmodified
// - uri: use the same value unmodified
// - coords: extract the array of [lng, lat] values from the geojson property
// - date: convert the created_at string property to a real JavaScript Date
// - name: use either the taxon's preferred_common_name or name property, converted to Title Case
// - photoUrl: use the taxon's default_photo square_url value
// - wikipediaUrl: use the taxon's wikipedia_url value
// - isNative: convert the taxon native value to a boolean
// - isIntroduced: convert the taxon introduced value to a boolean
// - isEndangered: convert the taxon endangered value to a boolean
// - isThreatened: convert the taxon threatened value to a boolean

function transformObservations(observations) {
  return observations.map(function (observation) {
    let data = {};

    data.id = observation.id;
    data.uri = observation.uri;
    data.coords = observation.geojson.coordinates;
    data.date = new Date(`${observation.identifications[0].created_at}`);
    data.name = titleCase(
      observation.taxon.preferred_common_name
        ? observation.taxon.preferred_common_name
        : observation.taxon.name
    );
    data.photoUrl = observation.taxon.default_photo
      ? observation.taxon.default_photo.square_url
      : null;
    data.wikipediaUrl = observation.taxon.wikipedia_url;
    data.isNative = observation.taxon.native;
    data.isIntroduced = observation.taxon.introduced;
    data.isEndangered = observation.taxon.threatened;
    data.isThreatened = observation.taxon.extinct;

    return data;
  });
}

// Take the array of observations and filter out any observations that haven't
// been identified yet (i.e., are missing the `taxon` property) and/or don't have
// a photo (i.e., are missing the `taxon.default_photo` property).
function filterObservations(observations) {
  return observations.filter(function (observation) {
    if (observation.taxon != null && observation.taxon.default_photo != null) {
      return observation;
    }
  });
}

// Process all observation data in the window.data.results array (see data.js)
// to a simpler format we can work with, and filter the observations to get
// rid of any that are missing data that we need.
function getAllObservations() {
  const filtered = filterObservations(data.results);
  const transformed = transformObservations(filtered);

  // TIP: if you need to see an Object while debugging, you can log it.
  // TODO: Remove this code when you're done debugging.
  // console.log("getAllObservations()", transformed);

  return transformed;
}

// Given an array of observations, filter out any that aren't native species
// and return the filtered array.
function filterOnlyNative(observations) {
  return observations.filter(function (observation) {
    if (observation.isNative) return observation;
  });
}

// Given an array of observations, filter out any that aren't introduced species
// and return the filtered array.
function filterOnlyIntroduced(observations) {
  return observations.filter(function (observation) {
    if (observation.isIntroduced) return observation;
  });
}
