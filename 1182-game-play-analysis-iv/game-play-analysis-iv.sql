with firstLogins as(
    select a.player_id, min(a.event_date) as firstlogin
    from activity a
    group by a.player_id
),
consecLogin as (
    select count(a.player_id) as num_logins
    from firstlogins f
    inner join activity a on f.player_id=a.player_id 
    and f.firstLogin=Date_sub(a.event_date,interval 1 day)
)
select
    round(
        (select c.num_logins from conseclogin c)/
        (select count(f.player_id)from firstLogins f),2) as fraction