# Write your MySQL query statement below
select distinct t1.num  as ConsecutiveNums from logs t1
join logs t2
on (t2.id-1 = t1.id and t2.num is not null and t1.num=t2.num) 
join logs t3
on (t3.id-2 = t1.id and t3.num is not null and t1.num=t3.num)
