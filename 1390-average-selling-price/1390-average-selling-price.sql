SELECT p.product_id, IFNULL(ROUND(SUM(u.units * p.price) / SUM(u.units), 2), 0) AS average_price
FROM UnitsSold u RIGHT JOIN Prices p
ON u.product_id = p.product_id AND p.start_date <= u.purchase_date AND p.end_date >= u.purchase_date
GROUP BY p.product_id