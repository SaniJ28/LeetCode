# Write your MySQL query statement below
with new_table as(
    select  person_name,
    sum(weight) over (order by turn)as cummulative_weight
    from queue
)
select person_name
from new_table where cummulative_weight<=1000
order By cummulative_weight desc
limit 1