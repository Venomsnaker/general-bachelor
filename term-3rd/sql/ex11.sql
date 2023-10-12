SELECT 
    e.employee_id,
    e.first_name,
    m.first_name
from employees e
join employees m
    ON e.reports_to = m.employee_id