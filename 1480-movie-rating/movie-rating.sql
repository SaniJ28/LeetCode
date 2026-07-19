# Write your MySQL query statement below
(select u.name  as results from users u join movieRating mr on 
u.user_id=mr.user_id
group by u.user_id
order by count(u.user_id) desc, name limit 1)
union all
(select title as results
from movieRating join Movies using (movie_id)
where extract(year_month from created_at)=202002
group by title
order by avg(rating) desc, title limit 1)