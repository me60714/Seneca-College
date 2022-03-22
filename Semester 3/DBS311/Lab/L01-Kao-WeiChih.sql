-- ***********************
-- Name: Wei-Chih Kao
-- ID: 158000190
-- Date: Sep. 17. 2021
-- Purpose: Lab 1 DBS311 NEE
-- ***********************

-- Question 1 –
-- Write a query to display the tomorrow’s date in the following format: 
-- January 10th of year 2019
-- the result will depend on the day when you RUN/EXECUTE this query. Label the column “Tomorrow”.
-- Q1 SOLUTION --

SELECT to_char(sysdate + 1, 'MONTH DD"th of year" YYYY') FROM dual;

-- Question 2 -
-- Define an SQL variable called “tomorrow”, assign it a value of tomorrow’s date and use it in an SQL statement. 
-- Here the question is asking you to use a Substitution variable.
-- Instead of using the constant values in your queries, you can use variables to store and reuse the values. 
-- Q2 SOLUTION --

define tomorrow = to_char(sysdate + 1, 'MONTH DD"th of year" YYYY');
SELECT &tomorrow as "Tomorrow"
FROM dual;
UNDEFINE tomorrow;

-- Question 3 -
-- For each product in category 2, 3, and 5, show product ID, product name, list price, and the new list price increased by 2%.
-- Display a new list price as a whole number. In your result, add a calculated column to show the difference of old and new list prices.
-- Q3 SOLUTION --

SELECT product_id as "Product ID", product_name as "Product Name", list_price as "List Price",
ROUND(list_price * 1.02) as "New Price",
ROUND(list_price * 1.02)-list_price as "Price Difference"
FROM products
WHERE category_id = 2 OR category_id = 3 OR category_id = 5
order by category_id, product_id
FETCH FIRST 10 ROWS ONLY; 

-- Question 4 -
-- For employees whose manager ID is 2, write a query that displays the employee’s Full Name and Job Title in the following format:
-- Summer, Payne is Public Accountant.
-- Q4 SOLUTION --

SELECT last_name ||', '|| first_name || ' is ' || job_title as "Employee Info"
FROM employees
WHERE manager_id = 2
ORDER BY employee_id;

-- Question 5 -
-- For each employee hired before October 2016, display the employee’s last name,
-- hire date and calculate the number of YEARS between TODAY and the date the employee was hired.
-- Q5 SOLUTION --

SELECT last_name as "Last Name", hire_date as "Hire Date", ROUND((SYSDATE - hire_date)/365, 0) as "Years Worked"
FROM employees
WHERE hire_date < '01-OCT-2016'
ORDER BY hire_date, "Years Worked"
FETCH FIRST 10 ROWS ONLY;

-- Question 6 -
-- Display each employee’s last name, hire date, and the review date,
-- which is the first Tuesday after a year of service, but only for those hired after January 1, 2016.
-- Q6 SOLUTION --

SELECT last_name as "Last Name", hire_date as "Hire Date", to_char(next_day((hire_date+365)+1,'Tuessday'),
'DAY", "Month" the "ddspth "of year "yyyy') as "Review Date"
FROM employees
WHERE hire_date > '01-JAN-2016'
ORDER by "Hire Date"
FETCH FIRST 10 ROWS ONLY;

-- Question 7 -
-- For all warehouses, display warehouse id, warehouse name, city, and state.
-- For warehouses with the null value for the state column, display “unknown”.
-- Sort the result based on the warehouse ID.
-- Q7 SOLUTION --

SELECT w.warehouse_id as "Warehouse ID", w.warehouse_name as "Warehouse Name", l.city,
CASE 
WHEN l.state is NULL THEN 'Unknown'
ELSE l.state
END as "State"
FROM warehouses w
LEFT JOIN locations l
ON w.location_id = l.location_id
ORDER BY w.warehouse_id
