# Write your MySQL query statement below
#select dept_id,count(*) as num from student group by dept_id

select d.dept_name, if(t.num is null,0,t.num) as student_number from department d
left join (select dept_id,count(*) as num from student group by dept_id) t
on d.dept_id = t.dept_id
order by student_number desc, dept_name
