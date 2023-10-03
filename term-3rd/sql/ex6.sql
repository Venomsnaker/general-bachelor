SELECT *
FROM customers
--WHERE first_name REGEXP 'ELKA|AMBUR
--WHERE last_name REGEXP 'EY$|ON$'
--WHERE last_name REGEXP '^MY' OR last_name REGEXP 'SE'
WHERE last_name REGEXP 'B[RU]'
