select salesperson.salpers_name, sum(price*qty) from sale, salesperson, product where sale.prod_id = product.prod_id and sale.salpers_id = salesperson. salpers_id group by salesperson.salpers_name having count(*) >= 3;

select A.salpers_name from (select salesperson.salpers_name, sum(price*qty) as revenue, count(*) as cnt from sale, salesperson, product where sale.prod_id = product.prod_id and sale.salpers_id = salesperson. salpers_id group by salesperson.salpers_name having cnt >= 3) A;

select salpers_name, count(*) as cnt from salesperson, sale where salesperson.salpers_id = sale.salpers_id group by salpers_name order by cnt desc limit 2;


/* 10/6 */
create table sale (sale_id int not null)
load data infile '/usr/var'
load data local infile '/Desktop/file'

select salpers_id, salpers_name, manager_id from salesperson where manager_id is not null and salpers_id in (select manager_id from salesperson);

insert into mid_mgmt (select salpers_id, salpers_name, manager_id from salesperson where manager_id is not null and salpers_id in (select manager_id from salesperson));

/* creates permanenet table */ 
create table bigsale as (select sale_id, data from sale where qty > 200);

delete from bigsale where sale_id = 2;

update sale set qty=qty+10 where sale_id=10;