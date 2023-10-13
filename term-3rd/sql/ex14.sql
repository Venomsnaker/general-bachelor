SELECT 
    customer_id,
    first_name,
    points,
    'Bronze' AS 'rank'
FROM customers
WHERE points < 2000
UNION
SELECT 
    customer_id,
    first_name,
    points,
    'Silver' AS 'rank'
FROM customers
WHERE points < 3000 AND points >= 2000
UNION
SELECT 
    customer_id,
    first_name,
    points,
    'Gold' AS 'rank'
FROM customers
WHERE points >= 3000
ORDER BY first_name
