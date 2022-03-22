-- ***********************
-- Name: Wei-Chih Kao
-- ID: 158000190
-- Date: Oct. 05. 2021
-- Purpose: Lab 3 DBS311 NEE
-- ***********************

-- Question 1 –-
-- Write a SQL query to display the last name and hire date of all employees
-- who were hired before the employee with ID 107 got hired but after March 2016.
-- Sort the result by the hire date and then employee ID.

-- Q1 Solution –-

SELECT
    last_name,
    hire_date
FROM
    employees
WHERE
    hire_date > '31/MAR/16'
    AND
    hire_date < (
    SELECT
        hire_date
    FROM
        employees
    WHERE
        employee_id = 107)
ORDER BY
    hire_date;

-- Question 2 –-

-- Write a SQL query to display customer name and credit limit for customers
-- with lowest credit limit. Sort the result by customer ID.

-- Q2 Solution –-

SELECT
    name,
    credit_limit
FROM
    customers
WHERE
    credit_limit = ANY
    (
        SELECT
            MIN(credit_limit)
        FROM
            customers
    )
ORDER BY
    customer_id;

-- Question 3 –-
-- Write a SQL query to display the product ID, product name, and list price
-- of the highest paid product(s) in each category.
-- Sort by category ID and the product ID.

-- Q3 Solution –-

SELECT
    category_id,
    product_id,
    product_name,
    list_price
FROM
    products
WHERE
    list_price IN
    (
        SELECT
            MAX(list_price)
        FROM
            products
        GROUP BY
            category_id
    )
ORDER BY category_id, product_id;

-- Question 4 –-
-- Write a SQL query to display the category ID and the category name of the
-- most expensive (highest list price) product(s).

-- Q4 Solution –-

SELECT
    category_id,
    category_name
FROM
    product_categories
WHERE
    category_id IN
    (
        SELECT
            category_id
        FROM
            products
        WHERE
            list_price IN
            (
                SELECT
                    MAX(list_price)
                FROM
                    products
            )
    );

-- Question 5 –-
-- Write a SQL query to display product name and list price for products in
-- category 1 which have the list price less than the lowest list price in ANY
-- category. Sort the output by top list prices first and then by the product ID.

-- Q5 Solution –-

SELECT
    product_name,
    list_price
FROM
    products
WHERE
    category_id = 1
    AND list_price < ANY
    (
        SELECT
            MIN(list_price)
        FROM
            products
        GROUP BY
            category_id
    )
ORDER BY
    list_price DESC,
    product_name;

-- Question 6 –-
-- Display the maximum price (list price) of the category(s) that has the
-- lowest price product.

-- Q6 Solution –-

SELECT
    MAX(list_price)
FROM
    products
WHERE
    category_id IN
    (
        SELECT
            category_id 
        FROM
            products 
        WHERE
            list_price IN 
            (
                SELECT
                    MIN(list_price) 
                FROM
                    products
            )            
    );
    

