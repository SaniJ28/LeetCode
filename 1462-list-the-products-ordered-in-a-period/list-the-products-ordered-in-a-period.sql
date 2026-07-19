# Write your MySQL query statement below
select product_name, sum(unit) as unit
from products p join orders o
on o.product_id=p.product_id
where order_date like '2020-02-%'
group by product_name
having sum(unit)>=100