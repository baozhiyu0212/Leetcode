# Write your MySQL query statement below
# First step : find the com_id of Company Red
# select com_id from company where name = 'red';
# Second step : find distinct result of sales_id who have sales_id
# select sales_id from orders where com_id = (select com_id from company where name = red);
# Third step : find final result

select name from salesperson where sales_id 
not in (select sales_id from orders where com_id = (select com_id from company where name = 'red'));
