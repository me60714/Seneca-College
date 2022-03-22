-- ***********************
-- Name: Wei-Chih Kao
-- ID: 158000190
-- Date: Sep. 28. 2021
-- Purpose: Lab 2 DBS311 NEE
-- ***********************

-- Question 1 –-
-- For each job title display the number of employees.
-- Sort the result according to the number of employees.

SELECT job_title, count(*) AS "EMPLOYEES"
FROM employees
GROUP BY job_title
Order by employees;

-- Question 2 --
-- Display the highest, lowest, and average customer credit limits.
-- Name these results high, low, and average.
-- Add a column that shows the difference between the highest and the lowest
-- credit limits named “High and Low Difference”.
-- Round the average to 2 decimal places.

SELECT
MAX(credit_limit) AS "HIGH", MIN(credit_limit) AS "LOW",
ROUND(AVG(credit_limit), 2) AS "AVERAGE",
MAX(credit_limit) - MIN(credit_limit) AS "High and Low Difference" 
FROM customers;

-- Question 3 --
-- Display the order id, the total number of products, and the total order
-- amount for orders with the total amount over $1,000,000. Sort the result
-- based on total amount from the high to low values.

SELECT order_id, SUM(quantity) AS "TOTAL_ITEMS",
SUM(quantity * unit_price) AS "TOTAL_AMOUNT" 
FROM order_items
GROUP BY order_id
HAVING SUM(quantity * unit_price) > 1000000
ORDER BY "TOTAL_AMOUNT" DESC;

-- Question 4 --
-- Display the warehouse id, warehouse name, and the total number of products
-- for each warehouse. Sort the result according to the warehouse ID.

SELECT w.warehouse_id, w.warehouse_name, SUM(i.quantity) AS "TOTAL_PRODUCTS"
FROM warehouses w
LEFT JOIN inventories i ON w.warehouse_id = i.warehouse_id
GROUP BY w.warehouse_id, w.warehouse_name
ORDER BY w.warehouse_id;

-- Question 5 --
-- For each customer display customer number, customer full name, and the total
-- number of orders issued by the customer.
-- * If the customer does not have any orders, the result shows 0.
-- * Display only customers whose customer name starts with ‘O’ and contains ‘e’.
-- * Include also customers whose customer name ends with ‘t’.
-- * Show the customers with highest number of orders first.

SELECT c.customer_id, c.name AS "customer name", COUNT(o.order_id) AS "total number of orders"
FROM customers c LEFT JOIN orders o
ON c.customer_id = o.customer_id
WHERE TRIM(UPPER(c.name)) like 'O%' AND c.name like '%e%' OR TRIM(c.name) like '%t'
GROUP BY c.customer_id, c.name
ORDER BY "total number of orders" DESC;

-- Question 6 --
-- Write a SQL query to show the total and the average sale amount for each
-- category. Round the average to 2 decimal places.

SELECT p.category_id, SUM(o.quantity * o.unit_price) AS "TOTAL_AMOUNT",
ROUND(AVG(o.quantity * o.unit_price), 2) AS "AVERAGE_AMOUNT"
FROM order_items o LEFT JOIN products p
ON o.product_id = p.product_id
GROUP BY p.category_id;


