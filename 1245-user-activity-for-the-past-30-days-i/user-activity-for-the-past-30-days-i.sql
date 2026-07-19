# Write your MySQL query statement below
select
    activity_date as day,
    count(distinct user_id) as active_users
from 
    activity
where 
    activity_date BETWEEN '2019-06-28' AND '2019-07-27'
group by day