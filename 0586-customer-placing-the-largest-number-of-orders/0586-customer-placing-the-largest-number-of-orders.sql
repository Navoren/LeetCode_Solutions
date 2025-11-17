# Write your MySQL query statement below
SELECT o.customer_number
FROM Orders o
JOIN Orders o2 
    ON o.customer_number = o2.customer_number
GROUP BY o.customer_number
ORDER BY COUNT(*) DESC
LIMIT 1;
