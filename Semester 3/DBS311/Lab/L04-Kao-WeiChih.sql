-- ***********************
-- Name: Wei-Chih Kao
-- ID: 158000190
-- Date: Oct.11.2021
-- Purpose: Lab 4 DBS311 NEE
-- ***********************

-- Question 1 –-
-- Display cities that no warehouse is located in them.

-- Q1 Solution –-

SELECT city
FROM locations
MINUS(
    SELECT l.city
    FROM locations l, warehouses w
    WHERE l.location_id = w.location_id
    );

-- Question 2 –-
-- Display the category ID, category name, and the number of products in
-- category 1, 2, and 5. In your result, display first the number of products
-- in category 5, then category 1 and then 2.

-- Q2 Solution –-

SELECT pc.category_id, pc.category_name, COUNT(product_id) AS "COUNT(*)"
FROM product_categories pc
LEFT JOIN products p
ON pc.category_id = p.category_id
WHERE pc.category_id = 5
GROUP BY pc.category_id, pc.category_name
UNION ALL
SELECT pc.category_id, pc.category_name, COUNT(product_id) AS "COUNT(*)"
FROM product_categories pc
LEFT JOIN products p
ON pc.category_id = p.category_id
WHERE pc.category_id = 1
GROUP BY pc.category_id, pc.category_name
UNION ALL
SELECT pc.category_id, pc.category_name, COUNT(product_id) AS "COUNT(*)"
FROM product_categories pc
LEFT JOIN products p
ON pc.category_id = p.category_id
WHERE pc.category_id = 2
GROUP BY pc.category_id, pc.category_name;

-- Question 3 –-
-- Display product ID for products whose quantity in the inventory is less than to 5.

-- Q3 Solution –-

SELECT product_id
FROM inventories
WHERE quantity < 5;

-- Question 4 –-
-- We need a single report to display all warehouses and the state that they
-- are located in and all states regardless of whether they have warehouses in
-- them or not. 

-- Q4 Solution –-

SELECT w.warehouse_name, l.state
FROM warehouses w
LEFT JOIN locations l
ON w.location_id = l.location_id
UNION
SELECT w.warehouse_name, l.state
FROM warehouses w
RIGHT JOIN locations l
ON w.location_id = l.location_id;


