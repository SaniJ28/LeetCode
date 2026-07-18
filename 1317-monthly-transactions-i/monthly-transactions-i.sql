# Write your MySQL query statement below
select 
    left(trans_date,7) AS month,
    country,
    count(*) as trans_count,
    sum(if(state='approved',1,0)) approved_count,
    sum(amount) trans_total_amount,
    sum(if(state='approved',amount,0)) approved_total_amount
from transactions
group by month, country