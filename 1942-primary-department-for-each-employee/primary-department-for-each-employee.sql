# Write your MySQL query statement below
select employee_id, department_id
from (
    select * , count(employee_id) over (partition by employee_id)as employeeCount
    from employee
)as EmployeePartition
where
EmployeeCount=1
or primary_flag='Y'