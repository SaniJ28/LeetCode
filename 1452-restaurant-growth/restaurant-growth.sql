SELECT 
    visited_on,
    SUM(total_daily_amount) OVER(
        ORDER BY visited_on 
        ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    ) AS amount,
    
    
    ROUND(
        AVG(total_daily_amount) OVER(
            ORDER BY visited_on 
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ), 
        2
    ) AS average_amount
FROM (
    
    SELECT visited_on, SUM(amount) AS total_daily_amount
    FROM Customer
    GROUP BY visited_on
) daily_summary
LIMIT 6, 999999;