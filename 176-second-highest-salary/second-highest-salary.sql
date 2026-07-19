select(
    select distinct salary
    from employee
    order by salary desc
    limit 1 offset 1
) as SecondHighestSalary