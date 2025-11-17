# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary as Salary
from Employee as e
right join Department as d
on e.departmentId = d.id
where(d.id, e.salary) in (
    select departmentId, max(salary)
    from Employee
    group by departmentId
);