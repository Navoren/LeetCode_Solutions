# Write your MySQL query statement below
select em2.unique_id, em.name
from Employees as em
left join EmployeeUNI as em2 
on em.id = em2.id;