# Write your MySQL query statement below
select *,
if(x+y<=z or x+z<=y or z+y<=x,'No','Yes') as triangle
from triangle