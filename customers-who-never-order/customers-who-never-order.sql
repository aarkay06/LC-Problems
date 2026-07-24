# Write your MySQL query statement below
select name as Customers
from customers
left join Orders
on Customers.id = Orders.customerId
WHERE Orders.customerId IS NULL;
