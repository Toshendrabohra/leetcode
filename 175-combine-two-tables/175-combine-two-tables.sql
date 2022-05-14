# Write your MySQL query statement below
Select firstname , lastname , address.city , address.state from person  
left join address on address.personid=person.personid ;