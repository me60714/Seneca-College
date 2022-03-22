-- ***********************
-- Name: Wei-Chih Kao
-- ID: 158000190
-- Date: Nov.03.2021
-- Purpose: Lab 5 DBS311 NEE
-- ***********************

SET SERVEROUTPUT ON

-- Question 1 –-
-- Write a store procedure that get an integer number and prints
-- The number is even.
-- If a number is divisible by 2. Otherwise, it prints
-- The number is odd.

-- Q1 Solution –-

CREATE OR REPLACE PROCEDURE EvenOdd(val IN INT)
AS

BEGIN
   IF MOD(val ,2) = 0 THEN
       DBMS_OUTPUT.PUT_LINE('The number is even.');
    ELSE
       DBMS_OUTPUT.PUT_LINE('The number is odd.');
    END IF;
EXCEPTION
    WHEN TOO_MANY_ROWS THEN
        DBMS_OUTPUT.PUT_LINE('Too many rows');
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No data found');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Other error');
END EvenOdd;
/
BEGIN
    EvenOdd(100);
    EvenOdd(99);
END;
/
-- Question 2 –-
-- Create a stored procedure named find_employee. This procedure gets an employee
-- number and prints the following employee information:
-- First name, Last name, Email, Phone, Hire date, Job title

-- Q2 Solution –-

CREATE OR REPLACE PROCEDURE find_employee (employeeID IN NUMBER)
AS
    firstName  VARCHAR2(255 BYTE);
    lastName VARCHAR2(255 BYTE);
    email VARCHAR2(255 BYTE);
    phone VARCHAR2(255 BYTE);
    hireDate date;
    jobTitle VARCHAR2(255 BYTE);
BEGIN
    SELECT first_name, last_name, email, phone, hire_date, job_title
    INTO firstName, lastName, email, phone, hireDate, jobTitle
    FROM employees
    WHERE employee_id = employeeID;
    DBMS_OUTPUT.PUT_LINE ('First name: ' || firstname);
    DBMS_OUTPUT.PUT_LINE ('Last name: ' || lastname);
    DBMS_OUTPUT.PUT_LINE ('Email: '||email);
    DBMS_OUTPUT.PUT_LINE ('Phone: ' || phone);
    DBMS_OUTPUT.PUT_LINE ('Hire date: ' || hiredate);
    DBMS_OUTPUT.PUT_LINE ('Job title: '||jobtitle);
EXCEPTION
    WHEN TOO_MANY_ROWS THEN
        DBMS_OUTPUT.PUT_LINE('Too many rows');
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No data found');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Other error');
END find_employee;
/
BEGIN
find_employee(107);
END;
/

-- Question 3 –-
-- Every year, the company increases the price of all products in one category.
-- For example, the company wants to increase the price (list_price) of products
-- in category 1 by $5. Write a procedure named update_price_by_cat to update the
-- price of all products in a given category and the given amount to be added to
-- the current price if the price is greater than 0. The procedure shows the number
-- of updated rows if the update is successful.
-- The procedure gets two parameters:
-- • category_id IN NUMBER
-- • amount NUMBER(9,2)

-- Q3 Solution –-

CREATE OR REPLACE PROCEDURE update_price_by_cat (categoryID IN NUMBER, amount IN NUMBER)
AS
    category_id products.category_id%type;
    listPrice products.list_price%type;
    Rows_updated NUMBER;
  
BEGIN
    UPDATE PRODUCTS
    SET list_price = list_price + amount
    WHERE category_id = categoryID
    AND
    list_price > 0;
    Rows_updated := sql%rowcount;
    DBMS_OUTPUT.PUT_LINE(Rows_updated || ' rows updated');
  
EXCEPTION
    WHEN TOO_MANY_ROWS THEN
        DBMS_OUTPUT.PUT_LINE('Too many rows');
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No data found');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Other error');
END update_price_by_cat;
/
BEGIN
    update_price_by_cat (1,5);
END;
/

-- Question 4 –-
-- Every year, the company increase the price of products whose price is less than
-- the average price of all products by 1%. (list_price * 1.01). Write a stored
-- procedure named update_price_under_avg. This procedure do not have any parameters.
-- You need to find the average price of all products and store it into a variable of
-- the same type. If the average price is less than or equal to $1000, update products’
-- price by 2% if the price of the product is less than the calculated average.
-- If the average price is greater than $1000, update products’ price by 1% if the price
-- of the product is less than the calculated average. The query displays an error message
-- if any error occurs. Otherwise, it displays the number of updated rows.

-- Q4 Solution –-

CREATE OR REPLACE PROCEDURE update_price_under_avg
AS
    avgPrice products.list_price%type;
    rows_updated NUMBER;

BEGIN
    SELECT
        AVG(list_price)
    INTO
        avgPrice
    FROM
        products;

    IF avgPrice <= 1000 THEN
        UPDATE products
        SET list_price = list_price * 1.02
        WHERE list_price < avgPrice;
        Rows_updated := sql%rowcount;
    ELSE
        UPDATE products
        SET list_price = list_price * 1.01
        WHERE list_price < avgPrice;
        Rows_updated := sql%rowcount;
    END IF;
    DBMS_OUTPUT.PUT_LINE(rows_updated || ' rows updated');
            
EXCEPTION
    WHEN TOO_MANY_ROWS THEN
        DBMS_OUTPUT.PUT_LINE('Too many rows');
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No data found');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Other error');
END update_price_under_avg;
/
BEGIN
    update_price_under_avg;
END;
/

-- Question 5 –-
-- The company needs a report that shows three category of products based their
-- prices. The company needs to know if the product price is cheap, fair, or expensive.

-- Q5 Solution –-

CREATE OR REPLACE PROCEDURE product_price_report
AS
    avg_price NUMBER;
    min_price NUMBER;
    max_price NUMBER;
    cheap_count NUMBER;
    fair_count NUMBER;
    exp_count NUMBER;

BEGIN

    SELECT AVG(list_price), MAX(list_price), MIN(list_price) INTO avg_price, max_price, min_price
    FROM products;
    
    SELECT COUNT(list_price) INTO cheap_count
    FROM products
    WHERE list_price < (avg_price - min_price) / 2;
    
    SELECT COUNT(list_price) INTO exp_count
    FROM products
    WHERE list_price > (max_price - avg_price) / 2;
    
    SELECT COUNT(list_price) INTO fair_count
    FROM products
    WHERE list_price >= (avg_price - min_price) / 2 AND list_price <= (max_price - avg_price) / 2;

    dbms_output.put_line('Cheap: ' ||cheap_count);
    dbms_output.put_line('Fair: ' ||fair_count);
    dbms_output.put_line('Expensive: ' ||exp_count);
    
EXCEPTION
    WHEN TOO_MANY_ROWS THEN
        DBMS_OUTPUT.PUT_LINE('Too many rows');
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('No data found');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Other error');     
END product_price_report;
/
BEGIN
product_price_report;
END;
/

