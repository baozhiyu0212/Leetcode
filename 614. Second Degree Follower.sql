# Write your MySQL query statement below

#select followee,count(*) as num from follow group by followee

select distinct f.follower as follower, t.num as num
from (select followee as name,count(distinct followee,follower) as num from follow group by followee) t
join follow f
on t.name in (f.follower) 
order by t.name
