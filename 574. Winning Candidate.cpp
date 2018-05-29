# Write your MySQL query statement below

#select candidateid,count(*) as num from vote group by candidateid order by num desc limit 1;

select c.Name from candidate c
join 
    (select candidateid,count(*) as num from vote group by candidateid order by num desc limit 1) t
on
    t.candidateid = c.id and c.name is not null;



