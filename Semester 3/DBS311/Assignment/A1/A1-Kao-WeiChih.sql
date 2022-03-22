-- ***********************
-- Name: Wei-Chih Kao
-- ID: 158000190
-- Date: Oct. 12. 2021
-- Purpose: Assignment 1 DBS311 NEE
-- ***********************

-- Task 1 –
-- Display the employee number, full employee name, job title, and hire date
-- of all employees hired in September with the most recently hired employees
-- displayed first.

-- TASK 1 SOLUTION --

SELECT
    employee_id AS "Employee Number",
    (last_name || ', ' || first_name) AS "Full Name",
    job_title AS "Job Title",
    to_char(hire_date, '[fmMonth ddth "of" yyyy]') AS "Start Date"
FROM
    employees
WHERE
    EXTRACT (MONTH FROM hire_date) = 9
ORDER BY
    hire_date DESC;

-- Task 2 –
-- The company wants to see the total sale amount per sales person (salesman)
-- for all orders. Assume that online orders do not have any sales representative.
-- For online orders (orders with no salesman ID), consider the salesman ID as 0.
-- Display the salesman ID and the total sale amount for each employee.
-- Sort the result according to employee number.

-- TASK 2 SOLUTION --

SELECT
   nvl(a.salesman_id, 0) AS "Employee number",
   to_char(SUM(b.unit_price * b.quantity),'$999,999,999.99') AS "Total Sale"
FROM
   orders a,
   order_items b 
WHERE
   a.order_id = b.order_id 
GROUP BY
   a.salesman_id,
   nvl(a.salesman_id, 0) 
ORDER BY
   nvl(a.salesman_id, 0);

-- Task 3 –
-- Display customer Id, customer name and total number of orders for customers
-- that the value of their customer ID is in values from 35 to 45. Include the
-- customers with no orders in your report if their customer ID falls in the
-- range 35 and 45.
-- Sort the result by the value of total orders.

-- TASK 3 SOLUTION --

SELECT
   c.customer_id AS "Customer Id",
   c.name AS "Name",
   COUNT(o.order_id) AS "Total Orders" 
FROM
   customers c 
   LEFT JOIN
      orders o 
      ON c.customer_id = o.customer_id 
WHERE
   c.customer_id BETWEEN 35 AND 45 
GROUP BY
   c.customer_id,
   c.name 
ORDER BY
   COUNT(o.order_id);

-- Task 4 –
-- Display customer ID, customer name, and the order ID and the order date of
-- all orders for customer whose ID is 44.
-- a. Show also the total quantity and the total amount of each customer’s order.
-- b. Sort the result from the highest to lowest total order amount.

-- TASK 4 SOLUTION --

SELECT
   c.customer_id AS "Customer Id",
   c.name AS "Name",
   o.order_id AS "Order Id",
   to_char(order_date, 'DD-MON-YY') AS "Order Date",
   SUM(quantity) AS "total Items",
   to_Char(SUM(quantity * unit_price),'$999,999,999.99') AS "Total Amount"
FROM
   customers c 
   JOIN
      orders o 
      ON c.customer_id = o.customer_id 
   JOIN
      order_items oi 
      ON o.order_id = oi.order_id 
WHERE
   c.customer_id = 44 
GROUP BY
   c.customer_id,
   c.name,
   o.order_id,
   order_date 
ORDER BY
   "Total Amount" DESC;

-- Task 5 –
-- Display customer Id, name, total number of orders, the total number of items
-- ordered, and the total order amount for customers who have more than 30 orders.
-- Sort the result based on the total number of orders.

-- TASK 5 SOLUTION --

SELECT
   c.customer_id AS "Customer Id",
   c.name AS "Name",
   COUNT(o.order_id) AS "Total Number of Orders",
   SUM(oi.quantity) AS "Total Items",
   to_char(SUM(oi.quantity * oi.unit_price),'$999,999,999.99') AS "Total Amount" 
FROM
   orders o,
   customers c,
   order_items oi 
WHERE
   c.customer_id = o.customer_id AND o.order_id = oi.order_id 
GROUP BY
   c.customer_id,
   c.name 
HAVING
   COUNT(o.order_id) > 30 
ORDER BY
   COUNT(o.order_id) ASC;

-- Task 6 –
-- Display Warehouse Id, warehouse name, product category Id, product category 
-- name, and the lowest product standard cost for this combination.
-- • In your result, include the rows that the lowest standard cost is less then $200.
-- • Also, include the rows that the lowest cost is more than $500.
-- • Sort the output according to Warehouse Id, warehouse name and then product
--   category Id, and product category name.

-- TASK 6 SOLUTION --

SELECT
   w.warehouse_id AS "Warehouse ID",
   w.warehouse_name AS "Warehouse Name",
   p.category_id AS "Category ID",
   pc.category_name AS "Category Name",
   to_char(MIN(p.standard_cost),'$999,999,999.99') AS "Lowest Cost"
FROM
   inventories i
   JOIN
      warehouses w
      ON i.warehouse_id = w.warehouse_id
   JOIN
      products p
      ON i.product_id = p.product_id
   JOIN
      product_categories pc
      ON p.category_id = pc.category_id
GROUP BY
   w.warehouse_id,
   w.warehouse_name,
   p.category_id,
   pc.category_name
HAVING
   MIN(p.standard_cost) < 200 
   OR MIN(p.standard_cost) > 500 
ORDER BY
   w.warehouse_id,
   w.warehouse_name,
   p.category_id,
   pc.category_name;

-- Task 7 –
-- Display the total number of orders per month. Sort the result from January to December.

-- TASK 7 SOLUTION --

SELECT
   to_char(to_date(month, 'MM'), 'Month') AS "Month",
   numOfMonth AS "Number of Orders"
FROM
   (
      SELECT
         EXTRACT(MONTH FROM order_date) AS month,
         COUNT(*) AS numOfMonth
      FROM
         orders
      GROUP BY
         EXTRACT(MONTH FROM order_date)
   )
ORDER BY
   month;

-- Task 8 –
-- Display product Id, product name for products that their list price is more
-- than any highest product standard cost per warehouse outside Americas regions.
-- (You need to find the highest standard cost for each warehouse that is located 
-- outside the Americas regions. Then you need to return all products that their 
-- list price is higher than any highest standard cost of those warehouses.)
-- Sort the result according to list price from highest value to the lowest.

-- TASK 8 SOLUTION --

SELECT
   product_id AS "Product Id",
   product_name AS "Product Name",
   to_char(list_price, '$999,999.99') AS "Price"
FROM
   products
WHERE
   list_price > ANY (
   SELECT
      MAX(standard_cost)
   FROM
      locations l
      JOIN
         countries c
         ON l.country_id = c.country_id
      JOIN
         regions r
         ON r.region_id = c.region_id
      JOIN
         warehouses w
         ON w.location_id = l.location_id
      JOIN
         inventories i
         ON i.warehouse_id = w.warehouse_id
      JOIN
         products p
         ON p.product_id = i.product_id
   WHERE
      region_name NOT LIKE 'Americas'
   GROUP BY
      w.warehouse_id)
   ORDER BY
      list_price DESC;

-- Task 9 –
-- Write a SQL statement to display the most expensive and the cheapest product 
-- (list price). Display product ID, product name, and the list price.

-- TASK 9 SOLUTION --

SELECT
   product_id AS "Product ID",
   product_name AS "Product Name",
   to_char(list_price,'$999,999.99') AS "Price" 
FROM
   products
WHERE
   list_price = (SELECT MAX(list_price) FROM products)
   OR
   list_price = (SELECT MIN(list_price) FROM products);

-- Task 10 –
-- Write a SQL query to display the number of customers with total order amount
-- over the average amount of all orders, the number of customers with total order
-- amount under the average amount of all orders, number of customers with no
-- orders, and the total number of customers.
-- See the format of the following result.

-- TASK 10 SOLUTION --

SELECT
   'Number of customers with total purchase amount over average: ' || COUNT(*) AS "Customer Report"
FROM
   (
      SELECT
         c.customer_id,
         SUM(oi.quantity * oi.unit_price) AS total_amount
      FROM
         customers c
         INNER JOIN
            orders o
            ON c.customer_id = o.customer_id
         INNER JOIN
            order_items oi
            ON oi.order_id = o.order_id
      GROUP BY
         c.customer_id
   )
WHERE
   total_amount >
   (
   SELECT
      AVG(quantity * unit_price)
   FROM
      order_items
    )
   UNION ALL
   SELECT
      'Number of customers with total purchase amount below average: ' || COUNT(*)
   FROM
      (
         SELECT
            c.customer_id,
            SUM(oi.quantity*oi.unit_price) AS total_amount
         FROM
            customers c
            INNER JOIN
               orders o
               ON c.customer_id = o.customer_id
            INNER JOIN
               order_items oi
               ON oi.order_id = o.order_id
         GROUP BY
            c.customer_id
      )
   WHERE
      total_amount <
      (
      SELECT
         AVG(quantity * unit_price)
      FROM
         order_items
      )
      UNION ALL
      SELECT
         'Number of customers with no orders: ' || COUNT(*)
      FROM
         (
            SELECT
               customer_id
            FROM
               customers minus 
               SELECT
                  customer_id
               FROM
                  orders
         )
      UNION ALL
      SELECT
         'Total number of customers: ' || COUNT(*)
      FROM
         (
            SELECT
               customer_id
            FROM
               customers
            UNION
            SELECT
               customer_id
            FROM
               orders
         );