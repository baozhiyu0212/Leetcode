# Write your MySQL query statement below
select if(t2.id is null,t1.id,t2.id) as id, t1.student from seat t1
left join seat t2
on (t1.id%2=1 and t2.id=t1.id+1) or (t1.id%2=0 and t2.id=t1.id-1)
