# Write your MySQL query statement below
select mgr.employee_id,
mgr.name,
count(emp.employee_id) as reports_count,
round(avg(emp.age),0) as average_age
from employees emp join employees mgr
on emp.reports_to=mgr.employee_id
group by mgr.employee_id
order by mgr.employee_id