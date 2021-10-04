/**
 * WEB222 – Assignment 1
 *
 * I declare that this assignment is my own work in accordance with
 * Seneca Academic Policy. No part of this assignment has been copied
 * manually or electronically from any other source (including web sites)
 * or distributed to other students.
 *
 * Please update the following with your information:
 *
 *      Name       : Wei-Chih Kao
 *      Student ID : 158000190
 *      Date       : 2021.06.11
 *
 * Please see all unit tests in the files problem-00.test.js, problem-01.test.js, etc.
 */

/*******************************************************************************
 * Problem 0: learn how to implement code to pass unit tests.
 *
 * Welcome to Assignment 1! In this assignment, you're going to be practicing lots
 * of new JavaScript programming techniques.  Before you dive in let's spend a
 * minute helping you learn how to read this code, and how to understand the
 * tests that go with it.
 *
 * In addition to this file, please also open the src/problem-00.test.js file.
 * Start by reading the comment at the top of that file, then come back here and
 * continue.
 *
 * Make sure you have completed the necessary Setup (install node.js, run `npm install`
 * before continuing).  The rest of the instructions assume that you have done this.
 *
 * After you finish reading src/problem-00.test.js, it's time to try running
 * the tests.  To run the tests, go to your terminal and type the following command:
 *
 *   npm test
 *
 * You have to run this command in the root of your project (i.e., in the same
 * directory as src/ and package.json).  When you do, you will see a lot of failures.
 * That's expected, since we haven't written any solution code yet.
 *
 * You can also run tests for only this problem instead of everything.  To do that:
 *
 *   npm test problem-00
 *
 * This will look for tests that are part of the problem-00.test.js file, and only
 * run those.  Doing so should result in 1 failed and 1 passed test.
 *
 * The first test passes:
 *
 *  ✓ greeting should be a function (2ms)
 *
 * But the second one failed:
 *
 * ✕ greeting should  return the correct string output (3ms)
 *
 * ● Problem 0 - greeting() function › greeting should  return the correct string output
 *
 *   expect(received).toBe(expected) // Object.is equality
 *
 *   Expected: "Hello WEB222 Student!"
 *   Received: "Hello WEB222 Student"
 *
 *     63 |   test('greeting should return the correct string output', function() {
 *     64 |     let result = greeting('WEB222 Student');
 *   > 65 |     expect(result).toBe('Hello WEB222 Student!');
 *        |                    ^
 *     66 |   });
 *     67 |
 *     68 |   /**
 *
 * We can see that the test 'greeting should say "Hello Name!"' is failing.
 * It's failing on line 65 of src/problem-00.test.js.  In particular, it's failing
 * because it expected to get the String "Hello WEB222 Student!" but instead
 * it actually received the String "Hello WEB222 Student".
 *
 * It looks like we have a small typo in our code below, and we are missing
 * the final "!"" character.  Try adding it below, save this file, and re-run the
 * tests again:
 *
 * npm test problem-00
 * PASS  src/problem-00.test.js
 *  Problem 0 - greeting() function
 *   ✓ greeting should be a function (2ms)
 *   ✓ greeting should return the correct string output
 *
 * Test Suites: 1 passed, 1 total
 * Tests:       2 passed, 2 total
 *
 * Excellent! At this point you're ready to move on to Problem 1. As you do,
 * read both the information in the Problem's comment, and also read the tests
 * to understand what they expect from your code's implementation.
 *
 * One final word about these comments.  You'll see comments like this one:
 *
 * @param {string} name - the name to greet in the message
 * @returns {string}
 *
 * These are specially formatted comments that define parameters to functions,
 * and tell us the type {string} or {number}, and also the parameter's name.
 * We also indicate the return type for functions.
 *
 * Finally, we also explain a bit about how the parameter is used, and what
 * data it will have, whether it's optional, etc.
 ******************************************************************************/

function greeting(name) {
  return `Hello ${name}!`;
}

/*******************************************************************************
 * Problem 1: replace all internal whitespace in a string value with dashes ('-'),
 * and make it UPPERCASE.
 *
 * We want to be able to convert a string to Upper Kebab Case style, so that it
 * contains no spaces, tabs, or dots, and all letters are upper case.
 *
 * The kebab() function should work like this:
 *
 * kebab('ABC') --> returns 'ABC' (all Upper Case, the string is unchanged)
 * kebab(' ABC ') --> returns 'ABC' (all Upper Case, leading/trailing whitespace removed)
 * kebab('abc') --> returns 'ABC' (the string was converted to upper case)
 * kebab('A BC') --> returns 'A-BC' (uppercase, single space replaced with -)
 * kebab('A BC') --> returns 'A-BC' (uppercase, single space replaced with -)
 * kebab('A   BC') --> returns 'A-BC' (uppercase, multiple spaces replaced with -)
 * kebab('A.BC') --> returns 'A-BC' (uppercase, period replaced with -)
 * kebab('A..  BC') --> returns 'A-BC' (uppercase, periods/spaces replaced with -)
 *
 * @param {string} value - a string to be converted
 * @return {string}
 ******************************************************************************/

function kebab(value) {
  value = value.replace(/\.+/g, "-").trim().toUpperCase();
  value = value.replace(/\s+/g, "-");
  value = value.replace(/\-+/g, "-");

  return value;
}

/*******************************************************************************
 * Problem 2: create an HTML <img> element for the given url and alt text.
 *
 * In HTML, we use markup syntax to indicate how browsers should format elements
 * of a web page.  For example, here is a URL to a cat picture:
 *
 * https://images.unsplash.com/photo-1513451713350-dee890297c4a?width=500
 *
 * Try navigating to it in your browser.  In order for a web page to know how to
 * interpret this URL (e.g., should we show the text of the URL itself, or use
 * it to load an image?), we have to use special markup.  The <img> element
 * is how we specify that a URL is to be interpreted as an image, see:
 * https://developer.mozilla.org/en-US/docs/Web/HTML/Element/img
 *
 * Here is how we might use HTML to markup this image:
 *
 * <img src="https://images.unsplash.com/photo-1513451713350-dee890297c4a?width=500" alt="Cat with ears down">
 *
 * Our <img> has two attributes:
 *
 * - src: the URL to use when downloading this image's data
 * - alt: the alternative text to display in non-visual browsing environments (e.g., screen readers)
 *
 * Write the createImg() function to accept a URL and alt text, and return the
 * properly formatted img element.  For example:
 *
 * createImg('https://images.unsplash.com/photo-1513451713350-dee890297c4a?width=500', 'Cat with ears down')
 *
 * should return the following string of HTML:
 *
 * '<img src="https://images.unsplash.com/photo-1513451713350-dee890297c4a?width=500" alt="Cat with ears down">'
 *
 * An <img> can also optionally contain a width attribute, for example:
 *
 * <img src="https://images.unsplash.com/photo-1513451713350-dee890297c4a?width=500" alt="Cat with ears down" width="300">
 *
 * In this case, the <img> element should use 300 pixels for its width.  Therefore,
 * your createImg() function should also accept a third argument, width:
 *
 * // No width given
 * createImg('https://images.unsplash.com/photo-1513451713350-dee890297c4a?width=500', 'Cat with ears down')
 * // Width of 300 given
 * createImg('https://images.unsplash.com/photo-1513451713350-dee890297c4a?width=500', 'Cat with ears down', 300)
 *
 * The returned <img> HTML string should be formatted as follows:
 *
 * - Remove leading/trailing whitespace from src and alt values before you use them
 * - The src and alt attribute values should be wrapped in double-quotes (e.g., src="...")
 * - There should be a single space between the end of one attribute and start of the next (e.g., src="..." alt="...")
 * - The width attribute should only be added if a valid integer value (number or string) is passed
 *   for the third argument.  Otherwise ignore it.
 *
 * @param {string} src - the src URL for the img
 * @param {string} alt - the alt text to use for the img
 * @param {string|number} width - (optional) the width of the img. Must be a valid integer
 * @returns {string}
 ******************************************************************************/

function createImg(src, alt, width) {
  let img;
  src = src.trim();
  alt = alt.trim();

  width > 0
    ? (img = `<img src="${src}" alt="${alt}" width="${width}">`)
    : (img = `<img src="${src}" alt="${alt}">`);
  return img;
}

/*******************************************************************************
 * Problem 3: extract Date from date string
 *
 * A date string is expected to be formatted as follows:
 *
 * YYYY-DD-MM
 *
 * Meaning, Year (4 digits), Day (2 digits), Month (2 digits).
 *
 * January 1, 2021 would therefore be the following date string:
 *
 * 2021-01-01
 *
 * Similarly, September 29, 2021 would be:
 *
 * 2021-29-09
 *
 * Write a function, parseDateString() that accepts a date string of the format
 * specified above, and returns a Date object, set to the correct day.
 *
 * To help developers using your function, you are asked to provide detailed error
 * messages when the date string is formatted incorrectly.  We will use the throw
 * statement to throw an error when a particular value is not what we expect, see:
 * https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/throw
 *
 * For example: parseDateString('01-01-01') should fail, because the year is
 * not 4 digits.  Similarly, parseDateString('2021-1-01') should fail because
 * the day is not 2 digits, and parseDateString('2021-01-1') should fail because
 * the month is not 2 digits.  Also, a totally invalid date string should also
 * cause an exception to be thrown, for example parseDateString(null) or
 * parseDateString("this is totally wrong").
 *
 * @param {string} value - a date string
 * @returns {Date}
 ******************************************************************************/

function parseDateString(value) {
  let formatOfValue = /(\d{4})-(\d{2})-(\d{2})/;

  if (!formatOfValue.test(value)) throw "error";

  if (value.substr(5, 2) > 12) value = value.replace(formatOfValue, "$1-$3-$2");

  let date = new Date(value);

  return date;
}

/*******************************************************************************
 * Problem 4: convert Date to date string with specified format.
 *
 * As above, a date string is expected to be formatted as follows:
 *
 * YYYY-DD-MM
 *
 * Meaning, Year (4 digits), Day (2 digits), Month (2 digits).
 *
 * Write a function, toDateString() that accepts a Date object, and returns a
 * date string formatted according to the specification above. Make sure your
 * day and month values are padded with a leading '0' if necessary (e.g., 03 vs. 3).
 *
 * NOTE: it should be possible to use parseDateString() from the previous question
 * and toDateString() to reverse each other. For example:
 *
 * toDateString(parseDateString('2021-29-01)) should return '2021-29-01'
 *
 * @param {Date} value - a date
 * @returns {string}
 ******************************************************************************/

function toDateString(value) {
  let date = new Date(value);

  date = `${date.getFullYear()}-${date.getDate()}-${date.getMonth() + 1}`;

  dateYear = date.split("-")[0];
  dateDate = date.split("-")[1];
  dateMonth = date.split("-")[2];

  if (dateDate.length == 1) dateDate = "0" + dateDate;

  if (dateMonth.length == 1) dateMonth = "0" + dateMonth;

  return `${dateYear}-${dateDate}-${dateMonth}`;
}

/*******************************************************************************
 * Problem 5: validate a coordinate
 *
 * Coordinates are defined as numeric, decimal values of Latitude and Longitude.
 * A example, the Seneca College Newnham campus is located at:
 *
 * Latitude: 43.7955 (positive number means North)
 * Longitude: -79.3496 (negative number means West)
 *
 * Write a function, validateCoord(), which accepts a latitude and longitude,
 * and returns true if they are both valid, or false if one or both are invalid.
 *
 * Valid Latitude values are decimal numbers between -90 and 90.
 *
 * Valid Longitude values are decimal numbers between -180 and 180.
 *
 * @param {number} lat - the latitude
 * @param {number} lng - the longitude
 * @returns {boolean}
 ******************************************************************************/

function validateCoord(lat, lng) {
  if (lat <= 90 && lat >= -90 && lng <= 180 && lng >= -180) return true;

  return false;
}

/*******************************************************************************
 * Problem 6, Part 1: format a coordinate as a string
 *
 * As above, coordinates are defined as numeric, decimal values of Latitude and Longitude.
 *
 * Write a function, formatCoord(), which accepts a latitude and longitude,
 * and returns a string formatted as follows:
 *
 * (lat, lng)
 *
 * For example:
 *
 * formatCoord(43.7955, -79.3496) should return the string '43.7955,-79.3496'.
 *
 * An optional third param, includeBrackets, determines whether or not to include
 * parenthesis around the formatted coordinate:
 *
 * formatCoord(43.7955, -79.3496) should return the string '43.7955,-79.3496'.
 * formatCoord(43.7955, -79.3496, true) should return the string '[43.7955,-79.3496]'.
 *
 * Use your validateCoord() function from Problem 5 to determine if the coordinate
 * is valid before you attempt to format it.  If the coordinate is not valid, throw
 * an exception.
 *
 * @param {number} lat - the latitude
 * @param {number} lng - the longitude
 * @param {boolean} includeBrackets - (optional) whether to include the square brackets
 * @returns {string}
 ******************************************************************************/

function formatCoord(lat, lng, includeBrackets) {
  if (validateCoord(lat, lng) && includeBrackets) {
    return `[${lat},${lng}]`;
  } else if (validateCoord(lat, lng)) {
    return `${lat},${lng}`;
  } else throw "error";
}

/*******************************************************************************
 * Problem 6, Part 2: format any number of coordinates as a string
 *
 * Similar to Problem 6 Part 1, you are asked to format lat, lng coordinates
 * into a string. However, where formatCoord() formats a single lat, lng pair,
 * the formatCoords() function (note the `s` suffix) is able to format any
 * number of lag, lng pairs.
 *
 * For example:
 *
 * formatCoords(43.7955, -79.3496) should return '[[43.7955,-79.3496]]'
 * formatCoords(43.7955, -79.3496, 43.7953, -79.3491) should return '[[43.7955,-79.3496], [43.7953,-79.3491]]'
 *
 * In your solution for formatCoords, use the formatCoord function you wrote above.
 *
 * The formatCoords() function can take any number of arguments, but they must all be numbers,
 * there must be an even number of them, and all lat, lng pairs should be valid.
 *
 * If any of these conditions are not met, throw an exception.
 *
 * @param {number} arguments - any number of arguments can be passed, but there must be an even number
 * @returns {string}
 ******************************************************************************/

function formatCoords(...values) {
  let str = "[";
  if (values.length % 2 != 0) {
    throw "error";
  }

  for (let i = 0, j = i + 1; i < values.length; i += 2) {
    if (i > 0) str += ", " + formatCoord(values[i], values[j], true);
    else str += formatCoord(values[i], values[j], true);
  }

  str += "]";

  return str;
}

/*******************************************************************************
 * Problem 7: determine MIME type from filename extension
 *
 * Web browsers and servers exchange streams of bytes, which must be interpreted
 * by the receiver based on their type.  For example, an HTML web page is
 * plain text, while a JPG image is a binary sequence.
 *
 * The Content-Type header contains information about a resource's MIME type, see:
 * https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Content-Type
 *
 * The MIME type is made-up of a `type` and a `subtype` separated by a `/` character.
 * The type is general, for example, 'text' or 'video'.  The subtype is more
 * specific, indicating the specific type of text, image, video, etc.  See:
 * https://developer.mozilla.org/en-US/docs/Web/HTTP/Basics_of_HTTP/MIME_types
 *
 * A number of common types are used in web development:
 *
 * mimeFromFilename('/User/Documents/readme.txt') --> returns 'text/plain'
 *
 * Your mimeFromFilename() function should support all of the following extensions
 * with and without the leading '.':
 *
 * - .html, .htm --> text/html
 * - .css --> text/css
 * - .js --> text/javascript
 * - .jpg, .jpeg --> image/jpeg
 * - .gif --> image/gif
 * - .bmp --> image/bmp
 * - .ico, .cur --> image/x-icon
 * - .png --> image/png
 * - .svg --> image/svg+xml
 * - .webp --> image/webp
 * - .mp3 --> audio/mp3
 * - .wav --> audio/wav
 * - .mp4 --> video/mp4
 * - .webm --> video/webm
 * - .json --> application/json
 *
 * NOTE: any other extension should use the `application/octet-stream` MIME type,
 * to indicate that it is an unknown stream of bytes (e.g., binary file). You should
 * also use `application/octet-stream` if the file has no extension.
 *
 * @param {string} filename - a filename
 * @returns {string}
 ******************************************************************************/

function mimeFromFilename(filename) {
  let extension;

  if (filename.indexOf(".html") != -1 || filename.indexOf(".htm") != -1)
    extension = "text/html";
  else if (filename.indexOf(".css") != -1) extension = "text/css";
  else if (filename.indexOf(".js") != -1 && filename.indexOf(".json") == -1)
    extension = "text/javascript";
  else if (filename.indexOf(".jpg") != -1 || filename.indexOf(".jpeg") != -1)
    extension = "image/jpeg";
  else if (filename.indexOf(".gif") != -1) extension = "image/gif";
  else if (filename.indexOf(".bmp") != -1) extension = "image/bmp";
  else if (filename.indexOf(".ico") != -1 || filename.indexOf(".cur") != -1)
    extension = "image/x-icon";
  else if (filename.indexOf(".png") != -1) extension = "image/png";
  else if (filename.indexOf(".svg") != -1) extension = "image/svg+xml";
  else if (filename.indexOf(".webp") != -1) extension = "image/webp";
  else if (filename.indexOf(".mp3") != -1) extension = "audio/mp3";
  else if (filename.indexOf(".wav") != -1) extension = "audio/wav";
  else if (filename.indexOf(".mp4") != -1) extension = "video/mp4";
  else if (filename.indexOf(".webm") != -1) extension = "video/webm";
  else if (filename.indexOf(".json") != -1) extension = "application/json";
  else extension = "application/octet-stream";

  return extension;
}

console.log(mimeFromFilename("styles.css"));

/*******************************************************************************
 * Problem 8, Part 1: generate license text and link from license code.
 *
 * Images, videos, and other resources on the web are governed by copyright.
 * Everything you find on the web is copyright to its creator automatically, and
 * you cannot reuse it unless you are granted a license to do so.
 *
 * Different licenses exist to allow creators to share their work. For example,
 * the Creative Commons licenses are a popular way to allow people to reuse
 * copyright material, see https://creativecommons.org/licenses/.
 *
 * Below is a list of license codes, and the associated license text explaining the code:
 *
 * CC-BY: Creative Commons Attribution License
 * CC-BY-NC: Creative Commons Attribution-NonCommercial License
 * CC-BY-SA: Creative Commons Attribution-ShareAlike License
 * CC-BY-ND: Creative Commons Attribution-NoDerivs License
 * CC-BY-NC-SA: Creative Commons Attribution-NonCommercial-ShareAlike License
 * CC-BY-NC-ND: Creative Commons Attribution-NonCommercial-NoDerivs License
 *
 * NOTE: any other licenseCode should use the URL https://choosealicense.com/no-permission/
 * and the explanation text, "All Rights Reserved"
 *
 * Write a function, generateLicenseLink(), which takes a license code, and returns
 * an HTML link to the appropriate license URL, and including the explanation text.
 *
 * For example:
 *
 * generateLicenseLink('CC-BY-NC') should return the following HTML string:
 *
 * '<a href="https://creativecommons.org/licenses/by-nc/4.0/">Creative Commons Attribution-NonCommercial License</a>'
 *
 * The URL is generated based on the license code:
 *
 * - remove the `CC-` prefix
 * - convert to lower case
 * - place formatted license code within URL https://creativecommons.org/licenses/[...here]/4.0/
 *
 * You can read more about HTML links at https://developer.mozilla.org/en-US/docs/Web/HTML/Element/a
 *
 * @param {string} licenseCode - a license code
 * @returns {string}
 ******************************************************************************/

function generateLicenseLink(licenseCode) {
  let licenseFormat = /CC-(BY)-*([A-Z]{0,2})-*([A-Z]{0,2}$)/;
  let htmlString =
    '<a href="https://creativecommons.org/licenses/[here]/4.0/">[here2]</a>';

  if (licenseFormat.test(licenseCode)) {
    if (RegExp.$2 == "" && RegExp.$3 == "") {
      htmlString = htmlString.replace("[here]", RegExp.$1.toLowerCase());
      htmlString = htmlString.replace(
        "[here2]",
        "Creative Commons Attribution License"
      );
    } else if (RegExp.$2 + RegExp.$3 == "NC") {
      htmlString = htmlString.replace(
        "[here]",
        RegExp.$1.toLowerCase() + "-" + RegExp.$2.toLowerCase()
      );
      htmlString = htmlString.replace(
        "[here2]",
        "Creative Commons Attribution-NonCommercial License"
      );
    } else if (RegExp.$2 + RegExp.$3 == "SA") {
      htmlString = htmlString.replace(
        "[here]",
        RegExp.$1.toLowerCase() + "-" + RegExp.$2.toLowerCase()
      );
      htmlString = htmlString.replace(
        "[here2]",
        "Creative Commons Attribution-ShareAlike License"
      );
    } else if (RegExp.$2 + RegExp.$3 == "ND") {
      htmlString = htmlString.replace(
        "[here]",
        RegExp.$1.toLowerCase() + "-" + RegExp.$2.toLowerCase()
      );
      htmlString = htmlString.replace(
        "[here2]",
        "Creative Commons Attribution-NoDerivs License"
      );
    } else if (RegExp.$2 + RegExp.$3 == "NCSA") {
      htmlString = htmlString.replace(
        "[here]",
        RegExp.$1.toLowerCase() +
          "-" +
          RegExp.$2.toLowerCase() +
          "-" +
          RegExp.$3.toLowerCase()
      );
      htmlString = htmlString.replace(
        "[here2]",
        "Creative Commons Attribution-NonCommercial-ShareAlike License"
      );
    } else if (RegExp.$2 + RegExp.$3 == "NCND") {
      htmlString = htmlString.replace(
        "[here]",
        RegExp.$1.toLowerCase() +
          "-" +
          RegExp.$2.toLowerCase() +
          "-" +
          RegExp.$3.toLowerCase()
      );
      htmlString = htmlString.replace(
        "[here2]",
        "Creative Commons Attribution-NonCommercial-NoDerivs License"
      );
    } else {
      htmlString =
        '<a href="https://choosealicense.com/no-permission/">All Rights Reserved</a>';
    }
  } else {
    htmlString =
      '<a href="https://choosealicense.com/no-permission/">All Rights Reserved</a>';
  }

  return htmlString;
}

/*******************************************************************************
 * Problem 9 Part 1: create a pure Boolean true/false value from a dataset
 *
 * A dataset contains fields that indicate a value is true or false.  However,
 * users have entered data in various formats over the years, for example:
 *
 * Yes, yes, YES, Y, t, TRUE, true, True, 1
 * No, no, NO, N, n, f, FALSE, false, False, 0, null, undefined, -1
 *
 * Write a function pureBool() which takes a String, Number, Boolean,
 * null, or undefined and attempts to convert it into a pure Boolean value.
 *
 * If the value is not one of the values above, throw an error with the error
 * message, 'invalid boolean value'.
 *
 * @param {string|number|boolean|null|undefined} value - a value to convert to true/false
 * @returns {bool}
 ******************************************************************************/

function pureBool(value) {
  let bool;

  if (value == true) bool = true;
  else if (value == false) bool = false;
  else if (typeof value == "number") {
    if (value == 1) bool = true;
    else if (value == -1 || value == 0) bool = false;
    else if (value > 0 || value < 0) throw "invalid boolean value";
    else bool = false;
  } else if (typeof value == "string") {
    if (value.toLowerCase() == "true" || value.toLowerCase() == "t")
      bool = true;
    else if (value.toLowerCase() == "yes" || value.toLowerCase() == "y")
      bool = true;
    else if (value.toLowerCase() == "false" || value.toLowerCase() == "f")
      bool = false;
    else if (value.toLowerCase() == "no" || value.toLowerCase() == "n")
      bool = false;
  } else if (value == null || value == undefined) bool = false;
  else throw "invalid boolean value";

  return bool;
}

/*******************************************************************************
 * Problem 9 Part 2: checking for all True or all False values in a normalized list
 *
 * Using your normalizeBoolean() function, create two new functions to check
 * if a list of arguments are all normalized True or normalized False values:
 *
 * all('Y', 'yes', 1) --> returns true
 * some('Y', 'no', 1) --> returns true
 * none('Y', 'invalid', 1) --> returns false
 *
 * allFalse('N', 'no', 0) --> returns true
 * allFalse('N', 'no', 0) --> returns false
 * allFalse('Y', 'invalid', 1) --> returns false (i.e., does not throw)
 *
 * Use try/catch syntax to avoid having allTrue() and allFalse() throw errors
 * when normalizeBoolean() throws on invalid data.
 ******************************************************************************/

function all(...values) {
  let bool;

  for (let i = 0; i < values.length; i++) {
    if (pureBool(values[i]) == false) bool = false;
    else bool = true;
  }

  return bool;
}

function none(...values) {
  let bool;

  for (let i = 0; i < values.length; i++) {
    if (pureBool(values[i]) == true) bool = false;
    else bool = true;
  }

  return bool;
}

/*******************************************************************************
 * Problem 10 - build a URL to query the iNaturalist Web API
 *
 * One of the data sources we'll be exploring in future assignments is
 * https://www.inaturalist.org.  Using iNaturalist, both hobbyist and professional
 * scientists can share sightings and help identify plants and animals in their
 * local area.
 *
 * As a web developer, you have access to this tremendous database of scientific
 * observations via the iNaturalist Web API (application programming interface):
 *
 * https://www.inaturalist.org/pages/api+reference#get-observations
 *
 * Querying the iNaturalist dataset for information involves formatting a URL
 * in a particular way.  As we know from week 1, a URL can contain optional
 * name=value pairs, see: https://web222.ca/weeks/week01/#urls
 *
 * For example:
 *
 *   https://www.store.com/search?q=dog includes q=dog
 *
 *   https://www.store.com?_encoding=UTF8&node=18521080011 includes
 *   both _encoding=UTF8 and also node=18521080011, separated by &
 *
 * We will write a buildUrl() function to build a URL for the iNaturalist API
 * based on arguments passed by the caller.
 *
 * The buildUrl() function accepts the following arguments:
 *
 * - q: a search string, for example "butterfly" or "Horse-chestnut"
 * - per_page: a number from 1 to 200, indicating how many results to return per page
 * - order: a string indicating sort order, with possible values of `asc` or `desc`
 * - license: a string indicating which items to return (e.g., which license they use). Possible
 *   values include: none, any, cc-by, cc-by-nc, cc-by-sa, cc-by-nd, cc-by-nc-sa, cc-by-nc-nd
 * - lat: a number, indicating the latitude to use for results
 * - lng: a number, indicating the longitude to use for results.
 *
 * Write an implementation of buildUrl() that accepts arguments for all of the above
 * parameters, validates them (e.g., perPage must be between 1 and 200, lat and lng
 * must be a valid coord, etc), and returns a properly formatted URL.
 *
 * For example:
 *
 * buildUrl('butterfly', 50, 'asc', 'cc-by', 43.7955, -79.3496) should return
 * the following URL:
 *
 * https://api.inaturalist.org/v1/observations?q=butterfly&per_page=50&order=asc&license=cc-by&lat=43.7955&lng=-79.3496
 *
 * NOTE: if any of the values passed to buildUrl() are invalid, an exception should be thrown.
 *
 * NOTE: make sure you properly encode the q value, since URLs can't
 * contain spaces or certain other characters. HINT: use the encodeURIComponent()
 * function to do this, see:
 *
 * https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/encodeURIComponent
 *
 * @param {string} q the query to use. Must be properly URI encoded
 * @param {number} perPage the number of results per page, must be 1-200
 * @param {string} order the sort order to use, must be one of asc or desc
 * @param {string} license the license to use, must be one of none, any, cc-by, cc-by-nc, cc-by-sa, cc-by-nd, cc-by-nc-sa, cc-by-nc-nd
 * @param {number} lat the latitude to use, must be a valid latitude (use validateCoord() function)
 * @param {number} lng the longitude to use, must be a valid longitude (use validateCoord() function)
 * @returns {string} the properly formatted iNaturalist URL
 ******************************************************************************/

function buildUrl(q, perPage, order, license, lat, lng) {
  let string;

  if (perPage < 1 || perPage > 200) throw "invalid page number";
  else if (order != "desc" && order != "asc") throw "invalid order";
  else if (
    license != "none" &&
    license != "any" &&
    license != "cc-by" &&
    license != "cc-by-nc" &&
    license != "cc-by-sa" &&
    license != "cc-by-nd" &&
    license != "cc-by-nc-sa" &&
    license != "cc-by-nc-nd"
  )
    throw "invalid license";
  else if (!validateCoord(lat, lng)) throw "invalid coordinate";
  else
    string = `https://api.inaturalist.org/v1/observations?q=${encodeURIComponent(
      q
    )}&per_page=${perPage}&order=${order}&license=${license}&lat=${lat}&lng=${lng}`;

  return string;
}

// Our unit test files need to access the functions we defined
// above, so we export them here.
exports.greeting = greeting;
exports.kebab = kebab;
exports.createImg = createImg;
exports.parseDateString = parseDateString;
exports.toDateString = toDateString;
exports.validateCoord = validateCoord;
exports.formatCoord = formatCoord;
exports.formatCoords = formatCoords;
exports.mimeFromFilename = mimeFromFilename;
exports.generateLicenseLink = generateLicenseLink;
exports.pureBool = pureBool;
exports.all = all;
exports.none = none;
exports.buildUrl = buildUrl;
