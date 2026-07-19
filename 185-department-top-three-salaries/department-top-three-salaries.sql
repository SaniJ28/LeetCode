# Write your MySQL query statement below
WITH employee_dept as(
    select d.id,
    d.name as department,
    salary,
    e.name as Employee,
    Dense_rank() over (partition by d.id order by salary desc) as rnk
    from department d join employee e
    on e.departmentid=d.id
)
select department,employee,salary
from employee_dept
where rnk<=3